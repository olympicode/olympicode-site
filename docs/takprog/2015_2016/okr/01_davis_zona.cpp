# include <stdio.h>

main() {
  int a, b, c, d;
  int cx, cy, dx, dy;
  int to, mo;
  int x1, y1, x2, y2;
  scanf("%d%d", &a, &b); 
  scanf("%d%d", &c, &d); 
  scanf("%d%d", &x1, &y1); 
  scanf("%d%d", &cx, &cy); 
  scanf("%d%d%d", &dx, &dy, &mo); 
  x2 = x1 + c - 1;
  y2 = y1 + d - 1;
  if ((dx == 0) && (dy == 0)) {
  	if ((cx >= x1) && (cx <= x2) && (cy >= y1) && (cy <= y2)) 
  	  printf("%d %d\n", cx, cy);
  	else
  	  printf("NE\n");
  	return 0;
  }
  to = 0;
  while (to <= mo) {
  	if ((cx >= x1) && (cx <= x2) && (cy >= y1) && (cy <= y2)) {
  	  printf("%d %d\n", cx, cy);
  	  return 0;
	}
	if ((cx+dx < 1) || (cx+dx > a)) {
	  dx = -dx;
	  if ((cy+dy < 1) || (cy+dy > b)) dy = -dy;
	  to++;
	} else {
	  if ((cy+dy < 1) || (cy+dy > b)) {
	    dy = -dy;	
	    to++;
	  }
	}
	if (to > mo) break;
	cx += dx; cy += dy;  
  }
  printf("NE\n");
  return 0;
}
