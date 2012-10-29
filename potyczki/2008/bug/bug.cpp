#include <stdio.h>

const int MAX_N = 200005;
const int MAX_M = 500005;
const int INFINITY = 200000005;

void downheap(int* dist, int* num, int* pos, int i) {
    int dist_tmp = dist[i];
    int num_tmp = num[i];
    int j, r = dist[0] >> 1;
    while (i <= r) {
        j = i << 1;
        if (j < dist[0] && dist[j + 1] < dist[j])
            ++j;
        if (dist_tmp < dist[j])
            break;
        dist[i] = dist[j];
        pos[num[j]] = i;
        num[i] = num[j];
        i = j;
    }
    dist[i] = dist_tmp;
    num[i] = num_tmp;
    pos[num_tmp] = i;
}

void upheap(int* dist, int* num, int* pos, int i) {
    int dist_tmp = dist[i];
    int num_tmp = num[i];
    int j = i >> 1;
    while (j > 0 && dist_tmp < dist[j]) {
        dist[i] = dist[j];
        pos[num[j]] = i;
        num[i] = num[j];
        i = j;
        j >>= 1;
    }
    dist[i] = dist_tmp;
    num[i] = num_tmp;
    pos[num_tmp] = i;
}

struct ListItem {
    int city;
    int dist;
    ListItem* next;
};

inline int min(int a, int b) {
    return a < b ? a : b;
}

void add_edge(ListItem** head, int a, int b, int c) {
    if (!head[a]){
        head[a] = new ListItem();
        head[a]->city = b;
        head[a]->dist = c;
        head[a]->next = NULL;
    }
    else {
        ListItem* tmp = new ListItem();
        tmp->city = b;
        tmp->dist = c;
        tmp->next = head[a];
        head[a] = tmp;
    }
}

int main() {
    int n, m, a, b, c;
    int dist_odd[MAX_N];
    int dist_even[MAX_N];
    int num_even[MAX_N];
    int num_odd[MAX_N];
    int pos_even[MAX_N];
    int pos_odd[MAX_N];
    ListItem* head[MAX_N];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        num_odd[i] = num_even[i] = i;
        pos_odd[i] = pos_even[i] = i;
        dist_odd[i] = dist_even[i] = INFINITY;
    }
    dist_even[0] = dist_odd[0] = n;
    dist_even[1] = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        add_edge(head, a, b, c);
        add_edge(head, b, a, c);
    }
    while (dist_odd[0]) {
        ListItem* edge;
        int city;
        int d;
        int size;
        
        int x;

//        printf("&&&&& %d, %d\n", even_heap.find_min()->dist, odd_heap.find_min()->dist);
        if (dist_even[0] && dist_even[1] <= dist_odd[1]) {
//            printf("wybieram even\n");
            city = num_even[1];
            edge = head[city];
            d = dist_even[1];
            size = dist_even[0];
            
            x = dist_even[1];
            dist_even[1] = dist_even[size];
            dist_even[size] = x;

            x = num_even[1];
            num_even[1] = num_even[size];
            num_even[size] = x;
            
            pos_even[num_even[1]] = 1;
            pos_even[num_even[size]] = size;

            --dist_even[0];
            downheap(dist_even, num_even, pos_even, 1);
        }

        else {
//            printf("wybieram odd\n");
            city = num_odd[1];
            edge = head[city];
            d = dist_odd[1];
            size = dist_odd[0];

            x = dist_odd[1];
            dist_odd[1] = dist_odd[size];
            dist_odd[size] = x;

            x = num_odd[1];
            num_odd[1] = num_odd[size];
            num_odd[size] = x;

            pos_odd[num_odd[1]] = 1;
            pos_odd[num_odd[size]] = size; 

            --dist_odd[0];
            downheap(dist_odd, num_odd, pos_odd, 1);

        }

/*for (int i = 1; i <= 6; ++i) {
            printf("%d, ", dist_even[i]);
        }
        printf("\npos:");
        for (int i = 1; i <= 6; ++i) {
            printf("%d, ", pos_even[i]);
        }
        printf("\nnum:");
        for (int i = 1; i <= 6; ++i) {
            printf("%d, ", num_even[i]);
        }
        printf("\n");*/



//        printf("######### wierzcholek %d, dist: %d\n", city, d);
        while (edge) {
            int tmp = d + edge->dist;
//            printf("  sasiad: %d nowe dist: %d\n", edge->city, tmp);
            if (tmp % 2 == 0) {
                if (tmp < dist_even[pos_even[edge->city]]) {
//                    printf("relaksuje even, stare: %d\n", dist_even[pos_even[edge->city]]);
                    dist_even[pos_even[edge->city]] = tmp;
                    upheap(dist_even, num_even, pos_even, pos_even[edge->city]);
                }
            }
            else {
                if (tmp < dist_odd[pos_odd[edge->city]]) {
//                    printf("relaksuje odd, stare: %d\n", dist_odd[pos_odd[edge->city]]);
                    dist_odd[pos_odd[edge->city]] = tmp;
                    upheap(dist_odd, num_odd, pos_odd, pos_odd[edge->city]);
                }
            }
            edge = edge->next;
        }
    }
//    printf("dupadupadupadupa\n");
    int ret = dist_odd[pos_odd[n]];
    if (ret == INFINITY)
        printf("0\n");
    else
        printf("%d\n", ret);
    return 0;
}
