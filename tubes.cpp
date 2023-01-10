#include "tubesh.h"
void createQueue(List &Q){
    head(Q) = NULL;
    tail(Q) = NULL;
}

void createElement(infotype x, adr &P){
    P = new Queue;
    info(P).burstTime = x.burstTime;
    info(P).name = x.name;
    info(P).waitingTime = 0;
    info(P).arroundTime = 0;
    next(P) = NULL;
}

void enqueue(List &Q, adr P){
    if (head(Q) == NULL){
        head(Q) = P;
        tail(Q) = P;
    } else {
        adr q = head(Q);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = P;
        tail(Q) = P;
    }
}

void dequeue(List &Q, adr &P){
    P = head(Q);
    if (head(Q) == NULL){
        cout << "Kosong\n";
    } else if(head(Q) == tail(Q)){
        head(Q) = NULL;
        tail(Q) = NULL;
    } else {
        head(Q) = next(head(Q));
        next(P) = NULL;
    }
}
bool isEmpty(List Q){
    return head(Q) == NULL && tail(Q) == NULL;
}
void show(List Q){
    adr q = head(Q);
    if (head(Q) == NULL && tail(Q) == NULL){
        cout << "Queue Kosong\n";
    } else {
        cout << left << setw(9) << "Job" << "| " <<setw(11) << "Burst Time" << "| " <<setw(13) << "Waiting Time" << "| " <<setw(13) << "Arround Time\n";
        while (q != NULL){
            cout << setw(9) << info(q).name
            << "| " <<setw(11) << info(q).burstTime
            << "| " <<setw(13) << info(q).waitingTime
            << "| " <<setw(13) << info(q).arroundTime << " \n";
            q = next(q);
        }
    }
}

void printJob(adr P){
    cout
    << "\nJob       : " << info(P).name
    << "\nBurstTime : " << info(P).burstTime
   << endl;
}

void AverageWT(float &x, int n){
    x = x/n;
}

void AverageTAT(float &y, int n){
    y = y/n;
}

List firstTimeFirstServe(List &Q1, List &Q2, List &Q3, int quantum, int prioritas, float &nWT, float &nTAT){
    int t;
    adr temp, P;
    List Qtemp;
    createQueue(Qtemp);
    while (!isEmpty(Q1)){
        cout << "\n====================================================\n";
        dequeue(Q1, temp);
        printJob(temp);
        cout << "Quantum   : " << quantum << endl;
        P = head(Q1);
        while (P != NULL){
            if (info(temp).burstTime <= quantum){
                info(P).waitingTime += info(temp).burstTime;
                info(P).arroundTime += info(temp).burstTime;
            } else if (info(temp).burstTime > quantum){
                info(P).waitingTime += quantum;
                info(P).arroundTime += quantum;
            }
            P = next(P);
        }
        P = head(Q2);
        while (P != NULL){
            if (info(temp).burstTime <= quantum){
                info(P).waitingTime += info(temp).burstTime;
                info(P).arroundTime += info(temp).burstTime;
            } else if (info(temp).burstTime > quantum){
                info(P).waitingTime += quantum;
                info(P).arroundTime += quantum;
            }
            P = next(P);
        }
        P = head(Q3);
        while (P != NULL){
            if (info(temp).burstTime <= quantum){
                info(P).waitingTime += info(temp).burstTime;
                info(P).arroundTime += info(temp).burstTime;
            } else if (info(temp).burstTime > quantum){
                info(P).waitingTime += quantum;
                info(P).arroundTime += quantum;
            }
            P = next(P);
        }
        if (info(temp).burstTime <= quantum){
            t += info(temp).burstTime;
            info(temp).arroundTime += info(temp).burstTime;
        } else if (info(temp).burstTime > quantum){
            t += quantum;
            info(temp).arroundTime += quantum;
        }
        

        show(Q1);

        info(temp).burstTime -= quantum;
        if (info(temp).burstTime > 0) {
            enqueue(Q1,temp);
        } else {
            info(temp).burstTime = 0;
            nTAT += info(temp).arroundTime;
            nWT += info(temp).waitingTime;
            cout
            << "\nJob          : " << info(temp).name
            << "\nWaiting Time : " << info(temp).waitingTime
            << "\nArround Time : " << info(temp).arroundTime << endl;
            enqueue(Qtemp, temp);
        }
        

        if (t%prioritas == 0){
            while (!isEmpty(Q2)){
                dequeue(Q2, temp);
                enqueue(Q1, temp);
            }

            while(!isEmpty(Q3)){
                dequeue(Q3, temp);
                enqueue(Q2, temp);
            }
        }
    }
    cout << "\n====================================================\n";
    return Qtemp;
}

int menu(){
    int i;
    cout 
    << "========================MENU========================\n"
    << "1. Masukan queue proses\n"
    << "2. Menampilkan Data\n"
    << "3. Execute\n"
    << "4. Menampilkan Rata - Rata WT dan TAT\n"
    << "5. Menampilkan List Kegiatan Setelah Eksekusi\n"
    << "6. Done\n"
    << "====================================================\n"
    << "Pilih: ";
    cin >> i;
    cout << "====================================================\n";
    return i;
}
