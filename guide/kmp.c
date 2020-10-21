#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn ((int)1e6 + 6)

char *s = NULL, *t = NULL;
int *nxt = NULL, // next 数组
    *oxt = NULL; // 优化的 next 数组
int slen = 0, tlen = 0;

void next() {
  nxt[0] = -1;
  oxt[0] = -1;
  int i = 0, j = -1;
  while (i < tlen) {
    if (j == -1 // 从模式串全串不匹配
        || t[i] == t[j]) {
      nxt[++i] = ++j;
      if (t[i] == t[j]) {
        oxt[i] = oxt[j];
      } else {
        oxt[i] = j;
      }
    } else {
      j = oxt[j];
      //   j = nxt[j];
    }
  }
}

void kmp() {
  int i = 0, j = 0;
  while (i < slen) {
    if (j == -1 || s[i] == t[j]) {
      ++j;
      ++i;
    } else {
      //   j = nxt[j];
      j = oxt[j];
    }
    if (j >= tlen) {
      printf("%d\n", i - tlen + 1);
      j = oxt[j]; // 查找下一个匹配位置
    }
  }
}

int main() {
  s = (char *)malloc(sizeof(char) * maxn);
  t = (char *)malloc(sizeof(char) * maxn);
  nxt = (int *)malloc(sizeof(int) * maxn);
  oxt = (int *)malloc(sizeof(int) * maxn);
  // 如果包含空格, fgets(s, maxn, stdin);  fgets 可能会读入回车符
  scanf("%s%s", s, t);
  slen = strlen(s);
  tlen = strlen(t);
  next();
  kmp();
  for (int i = 1; i <= tlen; i++) {
    printf("%d ", nxt[i]);
  }
  return 0;
}