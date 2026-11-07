// gerenciamento de memoria do sistema.
#include <WinSock2.h>
#include <iostream>
#include <memory>
#include <memory_resource>

using namespace std;
struct memoryqzz
{
    int id;
    double dados[100]; // simulando o uso de memoria ,voce pode mudar como bem entender
    
    
};


int main () {

    //buffer estatico de tamanho fixo(podendo ser usado tanto Stack, quanto Heap)
     alignas(memoryqzz) char bufferRAM[1024];
    std:: pmr::monotonic_buffer_resource pool(bufferRAM, sizeof(bufferRAM), std::pmr::null_memory_resource());
    // criação de um Deletor customizado com ligação com o ecossitema PMR]
    std::pmr::polymorphic_allocator<memoryqzz> alocador(&pool);
     
    auto pmr_deleter = [&alocador](memoryqzz* ptr) {
        std::allocator_traits<decltype(alocador)>::destroy(alocador,ptr);
        alocador.deallocate(ptr, 1);
        cout << "-> memoria volta ao POOL PMR DE FORMA SEGURA.\n";
    };

    // smart pointer conectado ao pool
    using PmrUniquePtr = unique_ptr<memoryqzz, decltype(pmr_deleter)>;

    try {
        cout << "tentativa de alocar dentro do limite\n";

// alocação direta no POOL
  
   memoryqzz* espacobruto = alocador.allocate(1);

   //contrução do objeto dentro do espaço
   memoryqzz* objectdone = ::new (espacobruto) memoryqzz{1, {0.0}};


   // colocamos o controle total para o unique_ptr, passivel a ser mudado futuramente também

   PmrUniquePtr ptr(objectdone, pmr_deleter);

   ptr ->id = 500;
   cout << "limitusageRAM" <<ptr ->id << "create with sucessed\n";
 }
   catch(const std::bad_alloc& e)
   //condição para evitar um uso indevido de RAM e o programa caira!

   {
    cerr << "Failed: O pool estourou seu limite de RAM pre-definido!\n";


   }
   cout <<" end of scope.\n";
   // o unique_ptr sai do escopo e chama o pmr_deleter, e o que estiver fora do escopo não será ocupado e nem usado na RAM.
   return 0;
}
