#include<iostream>
#include<iomanip>
using namespace std;
struct PriorityString

{

    int PageNo;

         PriorityString* link;

};

struct Frame

{

         int PageNo;

         Frame* left, *right;

};

class LeastRecentlyUsed

{

private:

         bool found;

         int PageFault;

         int TotalFrame;

         ///////Pointers////////

         PriorityString* head, *last;

         Frame* RecentlyUsed, *leastRecentlyUsed;

public:

         LeastRecentlyUsed(void);

         void Welcome(void);

         void TakeFrame(void);

         void ShowFault(void);

         void FindFault(void);

         void moveDownAndReplace(Frame* FindFrame, PriorityString* data);

         void EnterPriorityString(void);

         void ShowPriorityString(void);

         virtual ~LeastRecentlyUsed(void);

};

LeastRecentlyUsed::LeastRecentlyUsed(void)

{

         found = false;

         PageFault = 0;

         TotalFrame = 0;

         head =  NULL;

         last = NULL;

         RecentlyUsed = NULL;

         leastRecentlyUsed = NULL;

}

void LeastRecentlyUsed::moveDownAndReplace(Frame * FindFrame, PriorityString* data)

{

         Frame* temp = FindFrame;

         Frame* temp1 = FindFrame->left;

         cout << setw(25) << "Recently used" << setw(25) << "Previuosly used" << setw(25) << "Least  recently Used" << endl;

         cout << setw(25) << RecentlyUsed->PageNo  << setw(25) << RecentlyUsed->right->PageNo << setw(25) << leastRecentlyUsed->PageNo << endl; 

         while(temp1 != NULL)

         {

                  temp->PageNo = temp1->PageNo;

                  temp = temp1;

                  temp1 = temp1->left;

         }

         RecentlyUsed->PageNo = data->PageNo;

         cout << setw(25) << RecentlyUsed->PageNo  << setw(25) << RecentlyUsed->right->PageNo << setw(25) << leastRecentlyUsed->PageNo << endl; 

 

}

void LeastRecentlyUsed::FindFault(void)

{

         PriorityString* temp = head;

         Frame* FindFrame;

         while(head != NULL)

         {

                  temp = head;

                  head = head->link;

                  FindFrame = RecentlyUsed;

                  while(FindFrame->PageNo != -999 && FindFrame->right != NULL)

                  {

                           if(FindFrame->PageNo == temp->PageNo)

                           {

                                    found = true;

                                    break;

                           }

                           else

                           {

                                    FindFrame = FindFrame->right;

                           }

                  }//end inner while    

                  if(FindFrame == leastRecentlyUsed  && FindFrame->PageNo == temp->PageNo)

                  {

                           found = true;

                  }

                  moveDownAndReplace(FindFrame,temp);

                  //RecentlyUsed->PageNo = temp->PageNo;

                  delete temp;

                  if(found == false)

                  {        

                           PageFault++;

                  }

                  else

                           found = false;

         }// end outer while

}

void LeastRecentlyUsed::TakeFrame(void)

{

         cout << "How many free frame you want to take for process:_  ";

         cin >> TotalFrame;

         cout << endl;

         Frame * temp = new Frame;

         RecentlyUsed = temp;

         RecentlyUsed->PageNo = -999;

         leastRecentlyUsed = temp;

         temp->left = NULL;

         temp->right = NULL;

         for(int i = 1; i < TotalFrame; i++)

         {

                  temp = new Frame;

                  temp->right = NULL;

                  leastRecentlyUsed->right = temp;

                  temp->left = leastRecentlyUsed;

                  leastRecentlyUsed = temp;

                  leastRecentlyUsed->PageNo = -999;

         }

}

void LeastRecentlyUsed::ShowFault(void)

{

         cout << "Total page faults are:_ "

                  << PageFault << endl;

}

void LeastRecentlyUsed::EnterPriorityString(void)

{

         int length;

         cout << "Please specify length of PriorityString..." ;

         cin >> length;

         cout << endl;

         PriorityString* temp;

         int i = 0;

         while(i < length )

         {

                  temp = new PriorityString;

                  cout << "Please enter required page number:_ ";

                  cin >> temp->PageNo;

                  temp->link = NULL;

                  cout << endl;

                  if(head == NULL)

                  {

                           head = temp;

                           last = head;

                  }

                  else

                  {

                           last->link = temp;

                           last = temp;

                  }

 

                  i++;

 

         }// end while

}

void LeastRecentlyUsed::ShowPriorityString(void)

{

         PriorityString*temp = head;

         while(temp!=NULL)

         {

                  cout << temp->PageNo << "  ";

                  temp = temp->link;

         }

         cout << endl;

}

LeastRecentlyUsed::~LeastRecentlyUsed(void)

{

         PriorityString* temp = head;

         while(head != NULL)

         {

                  head = head->link;

                  delete temp;

                  temp = head;

         }

         Frame* tempframe = RecentlyUsed;

         while(tempframe != NULL)

         {

                  RecentlyUsed = RecentlyUsed->right;

                  if(RecentlyUsed != NULL)

                  {

                           RecentlyUsed->left = tempframe->left;

                  }

                  delete tempframe;

                  tempframe = RecentlyUsed;

         }

}

int main()

{

         LeastRecentlyUsed pro;

         pro.EnterPriorityString();

         pro.ShowPriorityString();

         pro.TakeFrame();

         pro.FindFault();

         pro.ShowFault();

         return 0;

}


