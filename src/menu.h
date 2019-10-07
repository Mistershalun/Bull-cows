void menu() {
  printf("1.Game\n2.Autors\n3.exit\n");
  int c;
  scanf("%d", &c);
  if (c == 1) {
    system("cls");
    set_word();
    game(1);
    system("cls");
  }
  if (c == 2) {
    system("cls");
    printf("Zaripov D.");
    scanf("%d");
    system("cls");
  }
  if (c == 3) {
    return;
  };
   system("cls");
  menu();
}
