#include <iostream>
#include <time.h>
#include <string.h>

struct nodeListwa {
    int key;
    double dVar;
    char cVar;
    struct nodeListwa* next;
};

class linkedListwa {
private:
    nodeListwa* head;
    nodeListwa* tail;
    int nodesAmount = 0;
public:
    linkedListwa() {
        head = NULL;
        tail = NULL;
    }
    
    ~linkedListwa() {}

    void addNode(int key) {
        nodeListwa* temp = new nodeListwa;
        temp->key = key;
        temp->dVar = rand() % 100000;
        strcpy(&temp->cVar, "T");
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
            std::cout << "Fist node inserted. Key: " << temp->key << " dVar: " << temp->dVar << " cVar: " << temp->cVar << std::endl << std::endl;
            nodesAmount++;
            return;
        }
        else {
            nodeListwa* current = head;

            while (current!=NULL) {
                if (current->key == key) {
                    std::cout << "Slot with key: " << key << " is taken. No nodes were inserted." << std::endl << std::endl;
                    return;
                }
                else {
                    if (current->key > key) {
                        temp->next = current;
                        head = temp;
                        std::cout<<"Inserted as new head. Key: " << temp->key << " dVar: " << temp->dVar << " cVar: " << temp->cVar << std::endl << std::endl;
                        nodesAmount++;
                        return;
                    }
                    if (current->key < key && current->next == NULL) {
                        current->next = temp;
                        tail = temp;
                        std::cout << "Inserted at the end. Key: " << temp->key << " dVar: " << temp->dVar << " cVar: " << temp->cVar << std::endl << std::endl;
                        nodesAmount++;
                        return;
                    }
                    if (current->key < key && current->next != NULL) {
                        if (current->next->key > key) {
                            temp->next = current->next;
                            current->next = temp;
                            std::cout << "Inserted in between. Key: " << temp->key << " dVar: " << temp->dVar << " cVar: " << temp->cVar << std::endl << std::endl;
                            nodesAmount++;
                            return;
                        }
                    }
                }
                current = current->next;
            }
        }

    }

    void addNodes(int amount) {
        for (int i = 0; i < amount; i++) {
            int randKey = (rand() % 99900) + 99;
            addNode(randKey);
        }
    }

    void removeNode(int key) {
        if (head == NULL) {
            std::cout << "Cannot remove anything. Linked list is empty" << std::endl << std::endl;
            return;
        }
        else {
            nodeListwa* current;
            nodeListwa* previous;

            if (key == 0) {
                current = head;
                head = head->next;
                std::cout << "Removing head - Key: " << current->key << " dVar: " << current->dVar << " cVar: " << current->cVar << std::endl;
                delete(current);
                nodesAmount--;
            }
            else {
                previous = current = head;
                while (key != current->key) {
                    if (current->next == NULL) {
                        std::cout << "Key: " << key << " not found. Nothing was removed" << std::endl << std::endl;
                        return;
                    }
                    previous = current;
                    current = current->next;
                }
                previous->next = current->next;
                std::cout << "Removing node - Key: " << current->key << " dVar: " << current->dVar << " cVar: " << current->cVar << std::endl;
                delete(current);
                nodesAmount--;
            }
        }
        std::cout << std::endl;
    }

    void removeAllNodes() {
        if (head == NULL) {
            std::cout << "Cannot remove anything. Linked list is empty" << std::endl << std::endl;
            return;
        }

        nodeListwa* current = head;
        nodeListwa* next = NULL;

        while (current != NULL) {
            next = current->next;
            std::cout << "Removing node - Key: " << current->key << " dVar: " << current->dVar << " cVar: " << current->cVar << std::endl;
            delete(current);
            nodesAmount--;
            current = next;
        }
        head = NULL;
        std::cout << std::endl;
    }

    void findKey(int key) {
        if (head == NULL) {
            std::cout << "Didn't find the key: " << key << ". Linked list is empty" << std::endl << std::endl;
            return;
        }

        nodeListwa* current = head;

        while (current != NULL) {
            if (current->key == key) {
                std::cout << "Found key: " << key << " dVar: " << current->dVar << " cVar: " << current->cVar << std::endl << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "Didn't find the key: " << key << std::endl << std::endl;
    }

    void displayNodesHead(int amount) {
        if (head == NULL) {
            std::cout << "Cannot display the list. Linked list is empty" << std::endl << std::endl;
            return;
        }

        nodeListwa* current = head;
        
        std::cout << "Linked list nodes from head:" << std::endl;

        for (int i = 0; i < amount; i++) {
            std::cout << "Key: " << current->key << " dVar: " << current->dVar << " cVar: " << current->cVar << std::endl;
            
            if (current->next != NULL) {
                current = current->next;
            }
            else {
                std::cout << std::endl;
                return;
            }
        }
        std::cout << std::endl;
    }

    void displayNodesTail(int amount) {
        if (head == NULL) {
            std::cout << "Cannot display anything. Linked list is empty" << std::endl << std::endl;
            return;
        }

        nodeListwa* current = head;
        int counter = 0;

        std::cout << "List from tail: " << std::endl;
        
        while (current != NULL) {
            if (counter >= nodesAmount - amount) {
                std::cout << "Key: " << current->key << " dVar: " << current->dVar << " cVar: " << current->cVar << std::endl;
            }
            counter++;
            current = current->next;
        }
        std::cout << std::endl;
    }

    void displayNodesAmount() {
        std::cout << "Nodes amount: " << nodesAmount << std::endl << std::endl;
    }
};

int main() {
    srand(time(0));

    clock_t begin, end;
    double totalTime;

    int X, k1, k2, k3, k4, k5;
    
    FILE* fp = fopen("inlab02.txt", "r");
    if (fp == NULL) return -1;
    fscanf(fp, "%d %d %d %d %d %d", &X, &k1, &k2, &k3, &k4, &k5);
    fclose(fp);

    std::cout << "Values from file: X: " << X << " k1: " << k1 << " k2: " << k2 << " k3: " << k3 << " k4: " << k4 << " k5: " << k5 << std::endl << std::endl;

    begin = clock();

    linkedListwa ll;
    
    ll.findKey(k1);
    ll.addNodes(X);
    ll.displayNodesAmount();
    ll.displayNodesHead(20);
    ll.addNode(k2);
    ll.displayNodesHead(20);
    ll.addNode(k3);
    ll.displayNodesHead(20);
    ll.addNode(k4);
    ll.displayNodesHead(20);
    ll.addNode(k5);
    ll.removeNode(k3);
    ll.displayNodesHead(20);
    ll.removeNode(k2);
    ll.displayNodesHead(20);
    ll.removeNode(k5);
    ll.displayNodesAmount();
    ll.findKey(k5);
    ll.displayNodesTail(11);
    ll.displayNodesAmount();
    ll.removeAllNodes();
    
    end = clock();
    totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %0.3fs\n", totalTime);

    return 0;
}