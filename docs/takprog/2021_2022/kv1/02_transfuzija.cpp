#include <cstdio>
#include <cstdlib>

enum GROUP { O, A, B, AB } ;

GROUP parse_group(const char *s) {
    if(s[0] == 'O') return O;
    else if(s[0] == 'A') return s[1] == 'B' ? AB : A;
    else return B;
}

struct patient {
    int use[4], todo;
    GROUP group;
} ;

const int N = 10005;
patient patients[N];
int have[4];

void transfer(int i, int type, int amount) {
    if(amount > have[type]) {
        printf("nemoguce\n");
        exit(0);
    }

    patients[i].todo -= amount;
    patients[i].use[type] += amount;
    have[type] -= amount;
}

void transfer_upto(int i, int type, int amount) {
    transfer(i, type, amount > have[type] ? have[type] : amount);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 4; i++)
        scanf("%d", &have[i]);
    
    for(int i = 0; i < n; i++) {
        char group[10];
        scanf(" %s %d", &group, &patients[i].todo);
        patients[i].group = parse_group(group);
    }

    for(int i = 0; i < n; i++)
        if(patients[i].group == O)
            transfer(i, O, patients[i].todo);

    for(int i = 0; i < n; i++)
        if(patients[i].group == A || patients[i].group == B) {
            transfer_upto(i, patients[i].group, patients[i].todo);
            transfer(i, O, patients[i].todo);
        }
    
    for(int i = 0; i < n; i++)
        if(patients[i].group == AB) {
            transfer_upto(i, O, patients[i].todo);
            transfer_upto(i, A, patients[i].todo);
            transfer_upto(i, B, patients[i].todo);
            transfer(i, AB, patients[i].todo);
        }

    printf("moguce\n");
    for(int i = 0; i < n; i++)
        printf("%d %d %d %d\n", patients[i].use[O], patients[i].use[A], patients[i].use[B], patients[i].use[AB]);

    return 0;
}
