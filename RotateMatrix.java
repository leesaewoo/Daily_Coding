//2차원 N x N 배열을 시계 방향으로 90도 씩 K번 회전시킨 배열을 리턴해야 합니다.
//인자 1: matrix
//가로 길이(matrix[i].length)와 세로 길이(matrix.length)가 모두 N인 2차원 배열
//matrix[i][j]는 int 타입
//빈 배열일 경우 matrix == null
//
//인자 2: K
//int 타입
//배열의 회전 수

public class RotateMatrix {
    public int[][] rotateMatrix(int[][] matrix, int K) {
        //배열의 길이가 짝수일때와 홀수일때의 방식이 다름
        if(matrix == null) {
            return null;
        }

        int arrayLength = matrix[0].length;
        boolean isOddNum = false;
        if(arrayLength % 2 == 1) {
            isOddNum = true;
        }

        int rotateCount = K % 4;

        for(int i = 0 ; i < rotateCount ; i++) {
            if (isOddNum) { //배열의 길이가 홀수일 때
                matrix = changeUpToDown(matrix, (arrayLength - 1) / 2);
            } else { // 배열의 길이 짝수일 때
                matrix = changeUpToDown(matrix, arrayLength / 2);
            }

            matrix = changeDiagonal(matrix);
        }

        return matrix;
    }

    private int[][] changeUpToDown(int[][] matrix, int baseLine) {
        for(int i = 0 ; i < baseLine ; i++) {
            for(int j = 0 ; j < matrix[0].length ; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[matrix.length - 1 - i][j];
                matrix[matrix.length - 1 - i][j] = temp;
            }
        }

        return matrix;
    }

    private int[][] changeDiagonal(int[][] matrix) {
        for(int i = 0 ; i < matrix.length ; i++) {
            for(int j = i ; j < matrix[0].length ; j++) {
                if(i != j) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        return matrix;
    }
}
