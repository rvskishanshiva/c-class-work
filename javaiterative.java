import java.util.Arrays;

public class javaiterative {

    public static void maxHeap(int[] arr, int n) {
        for (int i = 1; i < n; i++) {
            int item = arr[i];
            int key = i;
            int parent = (i - 1) / 2;

            while (key > 0 && item > arr[parent]) {
                arr[key] = arr[parent];
                key = parent;
                parent = (i - 1) / 2;
            }

            arr[key] = item;
        }
    }

    public static void heapSort(int[] arr, int n) {
        maxHeap(arr, n);
        int i = n - 1;

        while (i >= 0) {
            swap(arr, 0, i);
            i--;
            maxHeap(arr, i + 1);
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args)
 {
        int[] arr = {12, 11, 13, 5, 6, 7};
        int n = arr.length;

        System.out.println("Original array:");
        System.out.println(Arrays.toString(arr));

        heapSort(arr, n);

        System.out.println("Sorted array:");
        System.out.println(Arrays.toString(arr));
    }
}