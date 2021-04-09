#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[5];
        
        
    public : 

        time_t now = time(nullptr);
        char* dt = ctime(&now);

        Queue(){
            front = -1;
            rear = -1;
            for (int i = 0; i < 5; i++)
            {
                arr[i]=0;
            }
            

        }

        bool isEmpty()
        {
            if(front == -1 && rear == -1)
                return true;
            else 
                return false;
            
        }

        bool isFull()
        {
            if(rear==4)
                return true;
            else
                return false;
        }

        void enqueue (int val) 
        {
            if (isFull())
            {
                cout << "A fila esta cheia ";
                return;
            }
            else if (isEmpty())
            {
                rear = 0;
                front = 0;
                arr[rear]=val;
            }             
            else
            {
                rear++;
                arr[rear]=val;
            }
            
        }

        int dequeue () 
        {
            if(isEmpty())
            {
                cout << "A fila esta vazia ";
            }
            else if(front == rear)
            {
                int x;
                x = arr[front];
                arr[front]= 0;
                rear = -1;
                front = -1;
                return x;

                
            }
            else 
            {
                int x;
                x = arr[front];
                arr[front]= 0;
                front++;
                return x;
            }
        }

        

        void print (){
            cout << "Os valores abaixo sao:\n ";
            if(arr[0]==65){
                cout << "A marca escolhida a A ";
            }else if(arr[0]==66){
                cout << "A marca escolhida e a B";
                
            }else if(arr[0==81]){
                cout << "Voce escolheu qualquer marca";
            }
            
            cout << "\nEstante: " << arr[1];
            cout << "\nPrateleira: " << arr[2];
            cout << "\nGaveta: " << arr[3];
            cout << "\n Data: " << dt;
            
            


        
                      
        }

    
    
};


int main()
{

    //DATA 
    
    //time_t now = time(nullptr);
      



    int option,estante,prateleira,gaveta;
    char marca, opcao;
    Queue filaA;
    Queue filaB;
    Queue filaAny;

    do
    {
        cout << " O que voce deseja fazer?\n 1. Cadastrar um produto no estoque\n 2. Comprar um produto\n 3. Sair\n ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Digite a marca que voce quer cadatrar A  ou B ou Q (qualquer): ";
            cin >> marca;
            

            if (marca == 'A')
            {
                filaA.enqueue(marca);
                cout << "Digite a estante em que o produto esta: ";
                cin >> estante;
                filaA.enqueue(estante);
                cout << "Digite a prateleira em que o produto esta: ";
                cin >> prateleira;
                filaA.enqueue(prateleira);
                cout << "Digite a gaveta em que o produto esta: ";
                cin >> gaveta;
                filaA.enqueue(gaveta);
                //filaA.enqueue(now);
            }
            else if (marca == 'B')
            {
                filaB.enqueue(marca);
                cout << "Digite a estante em que o produto esta: ";
                cin >> estante;
                filaB.enqueue(estante);
                cout << "Digite a prateleira em que o produto esta: ";
                cin >> prateleira;
                filaB.enqueue(prateleira);
                cout << "Digite a gaveta em que o produto esta: ";
                cin >> gaveta;
                filaB.enqueue(gaveta);
                //filaB.enqueue(now);
            }else if (marca == 'Q')
            {
                filaAny.enqueue(marca);
                cout << "Digite a estante em que o produto esta: ";
                cin >> estante;
                filaAny.enqueue(estante);
                cout << "Digite a prateleira em que o produto esta: ";
                cin >> prateleira;
                filaAny.enqueue(prateleira);
                cout << "Digite a gaveta em que o produto esta: ";
                cin >> gaveta;
                filaAny.enqueue(gaveta);
                //filaAny.enqueue(now);
                
            }
             else 
            {
                cout <<"Digite uma opcao valida ";
            }

            break;
            
            

            
        case 2:

            cout << " Escolha a marca que voce deseja comprar (A OU B OU Q (qualquer)): ";
            cin >> opcao;

            if (opcao == 'A')
            {
                
                filaA.print(); 
                filaA.dequeue();            
                
                
            } 
            else if (opcao == 'B')
            {
                
                filaB.print();
                filaB.dequeue();
            }else if (opcao == 'Q')
            {
                filaAny.enqueue(estante);
                filaAny.enqueue(prateleira);
                filaAny.enqueue(gaveta);
                filaAny.print();
                filaAny.dequeue();
            } else {
                cout << "Digite uma opcao valida";
            }
                  
            break;
        case 3 :
            cout << "Programa encerrado ";
            break;

        
        
        }
    } while (option!=3);  
}