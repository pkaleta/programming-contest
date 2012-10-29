import java.util.Scanner;

public class B {

  public static void main (String [] args) {
    Scanner sc = new Scanner(System.in);
    int numCases = sc.nextInt();
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
      int R = sc.nextInt();
      int C = sc.nextInt();
      int D = sc.nextInt();
      int[][] mass = new int[R+1][C+1];
      for (int r = 0; r < R; r++) {
        String line = sc.next();
        for (int c = 0; c < C; c++) {
          char ch = line.charAt(c);
          mass[r+1][c+1] = ((int) ch) - 48;
        }
      }

      // HACK: use 1 indexing, everything with 0 index is initially 0

      int[][] x = new int[R+1][C+1];
      int[][] y = new int[R+1][C+1];
      int[][] m = new int[R+1][C+1];

      for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
          x[r][c] = x[r-1][c] + x[r][c-1] - x[r-1][c-1] + mass[r][c]*r;
          y[r][c] = y[r-1][c] + y[r][c-1] - y[r-1][c-1] + mass[r][c]*c;
          m[r][c] = m[r-1][c] + m[r][c-1] - m[r-1][c-1] + mass[r][c];
        }
      }

      int res = solve(R, C, mass, x, y, m);
      if (res > 0) {
        System.out.printf("Case #%d: %d\n", caseNum, res);
      }
      else {
        System.out.printf("Case #%d: %s\n", caseNum, "IMPOSSIBLE");
      }

    }
  }

  public static int solve(int R, int C, int[][] mass, int[][] x, int[][] y, int[][] m){
      for (int k = (R < C ? R : C); k >= 3; k--) {
        for (int r = 1; r + k - 1 <= R; r++) {
          for (int c = 1; c + k - 1 <= C; c++) {
            int rr = r + k - 1;
            int cc = c + k - 1;
            int xx = x[rr][cc] - x[rr][c-1] - x[r-1][cc] + x[r-1][c-1];
            int yy = y[rr][cc] - y[rr][c-1] - y[r-1][cc] + y[r-1][c-1];
            int mm = m[rr][cc] - m[rr][c-1] - m[r-1][cc] + m[r-1][c-1];
            for (int i = 0; i <= 1; i++) {
              for (int j = 0; j <= 1; j++) {
                int a = r + i * (k - 1);
                int b = c + j * (k - 1);
                xx -= mass[a][b] * a;
                yy -= mass[a][b] * b;
                mm -= mass[a][b];
              }
            }

            int mx = 2 * r + k - 1;
            int my = 2 * c + k - 1;

            if (mx * mm == 2 * xx && my * mm == 2 * yy) {
              return k;
            }

          }
        }
      }
      return 0;
  }
}
