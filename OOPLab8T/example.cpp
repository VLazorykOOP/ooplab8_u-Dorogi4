#include <iostream>
#include <algorithm>
#include <cstring>

namespace Fun {
    using namespace std;
    template <typename T>
    void swapMinMax(T arr[], int size) {
        if (size < 2) {
          
            return;
        }

        
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        
        std::swap(arr[minIndex], arr[maxIndex]);
    }

    void swapMinMax(char arr[], int size) {
        if (size < 2) {
           
            return;
        }

       
        std::sort(arr, arr + size);

      
        std::swap(arr[0], arr[size - 1]);
    }

    int fmain() {
        cout << "Task1 " << endl;
        cout << "--------------------------------------------------- " << endl;
        int arr1[] = { 1, 2, 3, 4, 5 };
        swapMinMax(arr1, 5);
        for (int i = 0; i < 5; i++) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;
        cout << "--------------------------------------------------- " << endl;
        cout  << endl;
        cout << endl;
        cout << endl;
       


        return 0;
    }
}
namespace Stk {
    using namespace std;

    template<typename T>
    void insertionSort(T arr[], int n) {
        int i, j;
        T key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    void insertionSort(const char* arr[], int n, int (*cmp)(const char*, const char*)) {
        int i, j;
        const char* key;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && cmp(arr[j], key) > 0) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }


    int cmp(const char* a, const char* b) {
        return strcmp(a, b);
    }

    int smain() {
        cout << "Task2 " << endl;
        cout << "--------------------------------------------------- " << endl;
        const char* arr[] = { "hello", "world", "this", "is", "a", "test" };
        int n = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, n, cmp);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
       
        cout <<  endl;
        cout << "--------------------------------------------------- " << endl;
        cout << endl;
        cout << endl;
        return 0;
    }
}
namespace task3 {

    using namespace std;

    template<typename T>
    class Queue {
    private:
        int frontIndex, rearIndex, maxSize;
        T* queue;

    public:
        Queue(int size) {
            frontIndex = rearIndex = -1;
            maxSize = size;
            queue = new T[size];
        }

        ~Queue() {
            delete[] queue;
        }

        bool isEmpty() const {
            return (frontIndex == -1 && rearIndex == -1);
        }

        bool isFull() const {
            return (rearIndex + 1) % maxSize == frontIndex;
        }

        void enqueue(T value) {
            if (isFull()) {
                cout << "Queue is full\n";
                return;
            }
            else if (isEmpty()) {
                frontIndex = rearIndex = 0;
            }
            else {
                rearIndex = (rearIndex + 1) % maxSize;
            }
            queue[rearIndex] = value;
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            else if (frontIndex == rearIndex) {
                frontIndex = rearIndex = -1;
            }
            else {
                frontIndex = (frontIndex + 1) % maxSize;
            }
        }

        T peek() const {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return T();
            }
            return queue[frontIndex];
        }

        void print() const {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            int i = frontIndex;
            while (i != rearIndex) {
                cout << queue[i] << " ";
                i = (i + 1) % maxSize;
            }
            cout << queue[rearIndex] << endl;
        }
    };

    int ts3main() {
        cout << "Task3 " << endl;
        cout << "--------------------------------------------------- " << endl;
        Queue<int> intQueue(5);
        intQueue.enqueue(10);
        intQueue.enqueue(20);
        intQueue.enqueue(30);
        intQueue.enqueue(40);
        intQueue.enqueue(50);
        intQueue.enqueue(60);
        intQueue.print();
        intQueue.dequeue();
        intQueue.dequeue();
        intQueue.print();
        cout << "Front element: " << intQueue.peek() << endl;

        Queue<string> stringQueue(5);
        stringQueue.enqueue("hello");
        stringQueue.enqueue("world");
        stringQueue.enqueue("this");
        stringQueue.enqueue("is");
        stringQueue.enqueue("a");
        stringQueue.enqueue("test");
        stringQueue.print();
        stringQueue.dequeue();
        stringQueue.dequeue();
        stringQueue.print();
        cout << "Front element: " << stringQueue.peek() << endl;


        cout << "--------------------------------------------------- " << endl;
        cout << endl;
        cout << endl;
        return 0;
    }


}
namespace task4 {

   using namespace std;
    template<typename T>
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;

        Node(T data) {
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    template<typename T>
    class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        class Iterator {
        private:
            Node<T>* current;

        public:
            Iterator(Node<T>* start) {
                this->current = start;
            }

            bool operator!=(const Iterator& other) const {
                return this->current != other.current;
            }

            T operator*() const {
                return this->current->data;
            }

            void operator++() {
                this->current = this->current->next;
            }
        };

        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;
        }

        void add(T data) {
            Node<T>* node = new Node<T>(data);
            if (this->head == nullptr) {
                this->head = node;
                this->tail = node;
            }
            else {
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
            this->size++;
        }

        Iterator begin() const {
            return Iterator(this->head);
        }

        Iterator end() const {
            return Iterator(nullptr);
        }

        int getSize() const {
            return this->size;
        }
    };

    int ts4main() {
        cout << "Task3 " << endl;
        cout << "--------------------------------------------------- " << endl;
        LinkedList<std::string> list;
        list.add("one");
        list.add("two");
        list.add("three");
        list.add("four");
        list.add("five");
        list.add("3");

        for (LinkedList<std::string>::Iterator it = list.begin(); it != list.end(); ++it) {
            std::cout << *it << " ";
        }
        cout << endl;
        cout << "--------------------------------------------------- " << endl;
        return 0;
    }

}

void example()
{
    Fun::fmain();
    Stk::smain();
    task3::ts3main();
    task4::ts4main();
}
