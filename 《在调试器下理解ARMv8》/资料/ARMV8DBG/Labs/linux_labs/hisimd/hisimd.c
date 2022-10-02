int a[256], b[256], c[256];
void foo () {
  int i;
#pragma GCC ivdep
  for (i=0; i<256; i++){
    a[i] = b[i] + c[i];
  }
}
int main(int argc, char ** argv)
{
    foo();
    return 0;
}
