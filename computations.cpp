/* Name: Anupriya Dubey
 * Submission Date: August 14, 2021
 * The following program aims to help students improve their studying habits, to build efficiency along with accuracy when preparing for future assignments 
 * and examinations.
*/

#include <iostream>
#include <string>
using namespace std;

struct Node{
    string question;
    string answer;
    Node *next;
};

//Queue Class
class Queue{

    public:
        Queue();
        ~Queue();
        bool isEmpty(){return (front == NULL);};
        void Enqueue(string q, string a);
        void startPractice(int numQ);
        void toString();
        
    private:
        Node *front;
        Node *back;
};

//constructor
Queue::Queue(){
    front = NULL;
    back = NULL;
}

//deconstructor 
Queue::~Queue(){
  Node *temp = front->next;
  delete front;
  while (front->next != back) {
    front = temp;
    temp = temp->next;
    delete front;
  }
  delete temp;
}

//Enqueue: add to the back of the queue
void Queue::Enqueue(string q, string a){
  if (isEmpty()) {
    front = new Node;
    front->question = q;
    front->answer = a;
    front->next = NULL;
    back = front;
  } else {
    Node *newNode = new Node;
    newNode->question = q;
    newNode->answer = a;
    back->next = newNode;
    back = newNode;
    back->next = NULL;
    
  }
}

void Queue::startPractice(int numQ){
    int numCorrect = 0;
    Node *current = front;
    string input = "";
    while(current != NULL){
      cout << "Question: " << current->question << endl;
      cout << "Response: ";
      cin >> input;

      //check if input answer matches preset answer
      if(input == current->answer){
        cout << "That is correct!" << endl;
        numCorrect++;
      }
      else{
        cout << "Incorrect." << endl;
      }

      cout << endl;
      //move on to next question
      current = current->next;
    }

    //cout << " \n" << endl;
    cout << "Score: " << numCorrect << "/" << numQ << endl;
    
    
}
void Queue::toString(){
    cout << endl;
    cout << "Here is a list of all of the questions that you tried today: " << endl;
    cout << endl;
    cout << "------------------ Problem Set and Solutions -------------------" << endl;
    cout << endl;
    Node *current = front;
    int count = 1;
    while(current != NULL){ 
        cout << "Question " << count << ": " << current->question << "     Answer: " << current->answer << endl;
        current = current->next;
        count++;
    }

}

int main() {

    Queue* questions = new Queue();

    int numQuestions = 0;
    string qAdd = "";
    string aAdd = "";
    cout << endl;
    cout << "Welcome to Computations! Before you can start working on your skills, lets set up the questions you will be practice today." << endl;
    cout << "Enter the number of questions you want to practice today: ";
    
    cin >> numQuestions;
    cin.ignore(1, '\n'); //takes care of extra space

//gets all practice questions and their corresponding answers from user
    for (int i = 0; i < numQuestions; i++){
        cout << "Enter question: ";
        getline(cin, qAdd);

        cout << "Enter corresponding answer: ";
        getline(cin, aAdd);
        
        questions->Enqueue(qAdd, aAdd);
        cout << endl;
    } 

    //start to practice questions
    questions->startPractice(numQuestions);
    
    questions->toString();

    delete questions;
  

    return 0;
}