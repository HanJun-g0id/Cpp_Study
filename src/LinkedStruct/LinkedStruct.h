// 리스트 구조체 정의
typedef struct {
    int* arr;          // 동적 배열
    int listMaxSize;   // 최대 크기
    int size;          // 현재 크기
    int created;       // 생성 여부 (bool 대신 int)
} List;

// 함수 선언
void List_Init(List* list);                   
void List_Create(List* list, int maxSize);    
void List_Destroy(List* list);                
void List_Insert(List* list, int pos, int item);
void List_Delete(List* list, int pos);
int  List_Retrieve(List* list, int item);
int  List_IsEmpty(List* list);
int  List_IsFull(List* list);
void List_Print(List* list);
void List_Append(List* list, int item);
void List_Pop(List* list);
void List_Reverse(List* list);
void List_Clear(List* list);
void List_Len(List* list);
void List_Sort(List* list);
void List_Extend(List* list);
void List_Copy(List* list);
void List_Sorted(List* list);
