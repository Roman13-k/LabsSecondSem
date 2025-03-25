#include <iostream>
#include <iomanip>
using namespace std;

struct Car {
    int year;
    double speed;
    char mark[20];
};

struct TNode {
    int l;
    int r;
    TNode* a;
};

struct stack {
    TNode* top = nullptr;
    void push(int lt, int rt) {
        TNode* spt = new TNode;
        spt->l = lt;
        spt->r = rt;
        spt->a = top;
        top = spt;
    }

    void pop(int& lt, int& rt) {
        TNode* spt = top;
        lt = spt->l;
        rt = spt->r;
        top = top->a;
        delete spt;
    }
};

void output(Car[],int&);
void puz(Car[],int&);
void shaker(Car[],int&);
void choise(Car[], int&);
void vst(Car [], int&);
void shell(Car[], int&);
void slip(int,int,Car[]);
void quickSort_Recur(Car[], int,int);
void quickSort_Cycle(Car[], int);

int main() {
    Car arr[] = {
        {2009, 300, "Audi"},
        {2000, 240, "BMW"},
        {2023, 267, "Mers"},
        {2003, 223, "Dasd"},
        {20043, 753, "Faasd"},
        {20054, 234, "Popasd"},
    };

    int size = sizeof(arr) / sizeof(arr[0]); 
    
    output(arr, size);
    cout << endl << "Sorting..." << endl << endl;

    /*puz(arr,size);*/
    /*shaker(arr,size);*/
    /*choise(arr, size);*/
    /*vst(arr, size);*/
    /*shell(arr, size);*/
   /* slip(0,size-1, arr);*/
    /*quickSort_Recur(arr,0,size-1);*/
    quickSort_Cycle(arr, size);

    output(arr, size);
    return 0;
}

void puz(Car arr[],int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j <=i; j++) {
            if (arr[i].speed > arr[j].speed) swap(arr[i], arr[j]);
        }
    }

}

void shaker(Car arr[],int &n) {
    int i,j,k=0,right=n, left = 0;
    do {
        for (j = n - 1; j > left; j--)
            if (arr[j - 1].speed > arr[j].speed) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        left = k + 1;
        for(i=1;i<right;i++)
            if (arr[i - 1].speed > arr[i].speed) {
                swap(arr[i - 1], arr[i]);
                k = i;
            }
        right = k - 1;
        
    } while (left<right);

}

void choise(Car arr[],int &n) {
    int imin;

    for (int i = 0; i < n; i++) {

        imin = i;
        for (int j = i + 1; j < n; j++) {
            if(arr[imin].speed > arr[j].speed) imin=j;
            if (imin != i) swap(arr[imin], arr[i]);
        }
    }

}

void vst(Car arr[], int &n) {
    int i, j;
    Car t;

    for (i = 1; i < n; i++) {
        t = arr[i];
        for (j = i - 1; j >= 0 && t.speed < arr[j].speed;j--) arr[j + 1] = arr[j];
        arr[j + 1] = t;
    }

}

void shell(Car arr[], int& n) {
    int i, j;
    Car t;

    for (int d = 3; d > 0; d--) {
        for (i = d; i < n; i += d) {
            t = arr[i];
            for (j = i - d; j >= 0 && t.speed < arr[j].speed; j -= d) arr[j + d] = arr[j];
            arr[j + d] = t;
        }
    }

}

void sl(int left, int right, int m, Car arr[]) {
    int i = left, j = m + 1, k = 0;
    Car* c = new Car[right - left + 1]; 

    while (i <= m && j <= right) {
        if (arr[i].speed < arr[j].speed)
            c[k++] = arr[i++];
        else
            c[k++] = arr[j++];
    }

    while (i <= m)
        c[k++] = arr[i++];
    while (j <= right)  
        c[k++] = arr[j++];

    for (k = 0, i = left; i <= right; k++, i++)
        arr[i] = c[k];

    delete[] c; 
}

void slip(int left,int right, Car arr[]) {
    if (left < right) {
        int m = (left + right) / 2;
        slip(left, m,arr);
        slip(m + 1, right, arr);
        sl(left, right, m, arr);
    }
}

void quickSort_Recur(Car arr[], int left,int right) {
    int i = left, j = right;
    Car x = arr[(i + j) / 2];

    do {
        while (arr[i].speed < x.speed) i++;
        while (arr[j].speed > x.speed) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i<=j);

    if (j > left)quickSort_Recur(arr, left, j);
    if (i < right) quickSort_Recur(arr, i, right);
}

void quickSort_Cycle(Car arr[], int n) {
    int i, j, left, right;
    Car x;
    stack st;
    st.push(0, n - 1);
    while (st.top) {
        st.pop(left, right);
        while (left < right) {
            i = left; j = right; x = arr[(left + right) / 2];
            while (i <= j) {
                while (arr[i].speed < x.speed) i++;
                while (arr[j].speed > x.speed) j--;

                if (i <= j) {
                    swap(arr[i], arr[j]);
                    i++;
                    j--;
                }
            }
            if (j - left < right - i) {
                if (i < right) st.push(i, right);
                right = j;
            }
            else {
                if (left < j) st.push(left, j);
                left = i;
            }
        }
    }
}

void output(Car arr[], int &n) {
    for (int i = 0; i < n; i++) {
        cout << setw(10) << arr[i].mark << " "
            << arr[i].year << " "
            << arr[i].speed << endl;
    }
    cout << endl;
}