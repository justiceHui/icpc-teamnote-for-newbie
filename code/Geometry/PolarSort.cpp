/* y축
   ↑
3  2 1
4 -1 0 → x축
5  6 7
원점 기준 각도 정렬
x축 위에 있는 점이 가장 먼저, 그리고 반시계 방향으로
*/
int QuadrantID(const Point p){
  static int arr[9] = { 5, 4, 3, 6, -1, 2, 7, 0, 1 };
  return arr[Sign(p.x)*3+Sign(p.y)+4];
}
sort(points.begin(), points.end(), [&](auto p1, auto p2){
  if(QuadrantID(p1) != QuadrantID(p2)) return QuadrantID(p1) < QuadrantID(p2);
  else return p1 / p2 > 0; // 반시계
});