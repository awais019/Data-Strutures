using System;

namespace recursion
{
    class Recursion{
        // prints the hello word n times
        static void hello(int n){
            if(n > 0){
                Console.WriteLine("Hello");
                hello(n-1);
            }
        }

        // factorial
        static int factorial(int n){
            if(n == 0 || n == 1){
                return 1;
            } else {
                return n*factorial(n-1);
            }
        }

        // prints string
        static void printString(string str){
            if(str.Length == 0){
                return;
            } else {
                Console.Write(str[0]);
                printString(str.Substring(1));
            }
        }

        // prints string in reverse
        static void printReverse(string str){
            if(str.Length == 0){
                return;
            } else {
                printReverse(str.Substring(1));
                Console.Write(str[0]);
            }
        }
        
        // count occurences of a character in  a string
        static int countChar(string str, char ch){
            if(str.Length == 0){
                return 0;
            } else if(str[0] ==  ch){
                return 1 + countChar(str.Substring(1), ch);
            } else {
                return 0 + countChar(str.Substring(1), ch);
            }
        }

        // replace ch1 with ch2
        static string replaceChar(string str, char ch1, char ch2){
            if(str.Length == 0){
                return str;
            } else if(str[0] == ch1){
                return ch2 + replaceChar(str.Substring(1), ch1, ch2);
            } else {
                return str[0] + replaceChar(str.Substring(1), ch1, ch2);
            }
        }

        static int searchArray(int[] arr, int start, int key){
            if(arr.Length == 0){
                return -1;
            } else if(arr[start] == key) {
                return start;
            } else {
                return searchArray(arr, start+1, key);
            }
        }

        // recursive selection sort
        static int findMax(int[] arr, int last){
            int maxIndex = 0;
            for(int i = 1; i <= last; i++){
                if(arr[i] > arr[maxIndex]){
                    maxIndex = i;
                }
            }
            return maxIndex;
        }

        static void swap(ref int a, ref int b){
            int temp = a;
            a = b;
            b = temp;
        }

        static void selectionSort(int[] arr, int last){
            if(last > 0){
                int maxIndex = findMax(arr, last);
                swap(ref arr[last], ref arr[maxIndex]);
                selectionSort(arr, last-1);
            }
        }
        static void Main(string[] args){
            int[] arr = { 1, 4, 2, 5, 3 };
            // swap(ref arr[3], ref arr[4]);
            selectionSort(arr, arr.Length-1);
            for(int i = 0; i < arr.Length; i++){
                Console.Write(arr[i] + " ");
            }
        }
    }
}