#include "endian.h"
int main() {
    uint8_t num1[] = {0x12, 0x34, 0x56};
    uint8_t num2[] = {0x12, 0x34, 0x57};
    int32_t result = endian_quality_test(num1, sizeof(num1), 0, num2, sizeof(num2), 1);
    uint8_t *a=NULL;
    endian_convert(num1,sizeof(num1),&a);
    printf("num1_convert: %d,%d,%d\n",a[0],a[1],a[2]);
    printf("Estimate: \n");
    if (result == 1) {
        printf("num1 > num2\n");
    } else if (result == -1) {
        printf("num1 < num2\n");
    } else {
        printf("num1 == num2\n");
    }

    return 0;
}
