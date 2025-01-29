#include <iostream>

template <typename T>
class MyPriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
    };

    Node* head;
    int count;

public:
    MyPriorityQueue() : head(nullptr), count(0) {}

    ~MyPriorityQueue() {
        while (head) {
            pop();
        }
    }

    void push(T item, int priority) {
        Node* newNode = new Node{item, priority, nullptr};

        if (!head || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        count++;
    }

    T pop() {
        if (!head) {
            throw std::runtime_error("Queue is empty");
        }
        Node* temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        count--;
        return data;
    }

    T peek() const {
        if (!head) {
            throw std::runtime_error("Queue is empty");
        }
        return head->data;
    }

    int size() const {
        return count;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyPriorityQueue<T>& queue) {
        Node* current = queue.head;
        os << "Priority Queue: ";
        while (current) {
            os << "(" << current->data << ", priority: " << current->priority << ") ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    std::cout << "Priority Queue with int:\n";
    MyPriorityQueue<int> pqInt;
    pqInt.push(10, 1);
    pqInt.push(20, 3);
    pqInt.push(30, 2);

    std::cout << pqInt << '\n';
    std::cout << "Peek: " << pqInt.peek() << '\n';
    std::cout << "Pop: " << pqInt.pop() << '\n';
    std::cout << pqInt << '\n';

    std::cout << "\nPriority Queue with double:\n";
    MyPriorityQueue<double> pqDouble;
    pqDouble.push(2.5, 1);
    pqDouble.push(1.1, 2);
    pqDouble.push(3.7, 3);

    std::cout << pqDouble << '\n';
    std::cout << "Peek: " << pqDouble.peek() << '\n';
    std::cout << "Pop: " << pqDouble.pop() << '\n';
    std::cout << pqDouble << '\n';

    std::cout << "\nPriority Queue with std::string:\n";
    MyPriorityQueue<std::string> pqString;
    pqString.push("Low", 1);
    pqString.push("Medium", 2);
    pqString.push("High", 3);

    std::cout << pqString << '\n';
    std::cout << "Peek: " << pqString.peek() << '\n';
    std::cout << "Pop: " << pqString.pop() << '\n';
    std::cout << pqString << '\n';

    return 0;
}