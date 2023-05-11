import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String string = bufferedReader.readLine();
        String[] stringArr = string.split(" ");

        int N = Integer.parseInt(stringArr[0]);
        int K = Integer.parseInt(stringArr[1]);
        int[] A = new int[N];

        string = bufferedReader.readLine();
        stringArr = string.split(" ");

        for(int i = 0 ; i < N ; i ++) {
            A[i] = Integer.parseInt(stringArr[i]);
        }

        int[] count = {0};
        merge_sort(A, 0, N - 1, count, K);

        if(count[0] < K) {
            System.out.println(-1);
        }
    }

    public static void merge_sort(int[] arr, int p, int q, int[] count, int K) {
        if(p < q) {
            int mid = (p + q) / 2;

            merge_sort(arr, p, mid, count, K);
            merge_sort(arr, mid + 1, q, count, K);
            merge(arr, p, mid, q, count, K);
        }
    }

    public static void merge(int[] arr, int p, int mid, int q, int[] count, int K) {
        int[] temp = new int[arr.length];

        int i = p;
        int j = mid + 1;
        while(i <= mid && j <= q) {
            if(arr[i] <= arr[j]) {
                i++;
            }
            else {
                temp[i] = arr[j];
                temp[j] = arr[i];
                i++;
                j++;
            }
        }

        while(i <= mid) {
            temp[i] = arr[q];
            temp[q] = arr[i];
            i++;
        }

        for(int k = p ; k <= q ; k++) {
            arr[k] = temp[k];
            count[0]++;
            if(count[0] == K) {
                System.out.println(arr[k]);
            }
        }
    }
}
