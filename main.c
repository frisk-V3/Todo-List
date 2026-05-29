#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TITLE 50

// タスクを表す構造体
typedef struct {
    int id;
    char title[MAX_TITLE];
    int is_completed; // 0: 未完了, 1: 完了
} Task;

Task todo_list[MAX_TASKS];
int task_count = 0;

// タスク一覧を表示する関数
void show_tasks() {
    printf("\n--- ToDo List ---\n");
    if (task_count == 0) {
        printf("タスクはありません。\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("[%s] ID:%d - %s\n", 
            todo_list[i].is_completed ? "✔" : " ", 
            todo_list[i].id, 
            todo_list[i].title);
    }
}

// タスクを追加する関数
void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("エラー: これ以上タスクを追加できません。\n");
        return;
    }
    
    printf("タスク名を入力: ");
    // scanfの改行対策をしつつ文字列を入力
    scanf(" %[^\n]", todo_list[task_count].title); 
    
    todo_list[task_count].id = task_count + 1;
    todo_list[task_count].is_completed = 0;
    
    task_count++;
    printf("タスクを追加しました！\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n1:一覧表示 | 2:タスク追加 | 0:終了\n選択してください: ");
        if (scanf("%d", &choice) != 1) {
            printf("数値を入力してください。\n");
            break;
        }
        
        if (choice == 1) {
            show_tasks();
        } else if (choice == 2) {
            add_task();
        } else if (choice == 0) {
            printf("アプリを終了します。\n");
            break;
        } else {
            printf("無効な選択です。\n");
        }
    }
    return 0;
}
