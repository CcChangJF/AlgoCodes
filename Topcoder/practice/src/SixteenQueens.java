import java.util.ArrayList;

public class SixteenQueens {
    private int[] existRows;
    private int[] existCols;
    ArrayList<Integer> newQueens;

    private boolean isValid(int row, int col) {
        for (int i = 0; i < existRows.length; ++i) {
            if (row == existRows[i] || col == existCols[i] ||
                    Math.abs(existRows[i] - row) == Math.abs(existCols[i] - col)) {
                return false;
            }
        }
        for (int i = 0; i < newQueens.size(); i = i + 2) {
            if (row == newQueens.get(i) || col == newQueens.get(i + 1) ||
                    Math.abs(newQueens.get(i) - row) == Math.abs(newQueens.get(i + 1) - col)) {
                return false;
            }
        }
        return true;
    }

    private void search(int add, int curRow, int curCol) {
        if (0 == add) {
            return;
        } else {
            if (isValid(curRow, curCol)) {
                newQueens.add(curRow);
                newQueens.add(curCol);
                search(add - 1, curRow + 1, 0);
            } else {
                if (curCol == 50) {
                    curCol = 0;
                    curRow = curRow + 1;
                }
                search(add, curRow, curCol + 1);
            }
        }
    }

    public int[] addQueens(int[] row, int[] col, int add) {
        if (0 == add) {
            return new int[0];
        }
        existRows = row;
        existCols = col;
        newQueens = new ArrayList<>();
        search(add, 0, 0);
        int[] res = new int[newQueens.size()];
        for (int i = 0; i < newQueens.size(); ++i) {
            res[i] = newQueens.get(i);
        }
        return res;
    }
}
