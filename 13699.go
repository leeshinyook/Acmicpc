package main

import "fmt"


func main() {
  var N int
  var dp [36] int64
   dp[0] = 1
   fmt.Scanf("%d", &N)
   for i := 1; i <= 35; i++ {
       for j := 0; j < i; j++ {
         for k := i - 1; k >= 0; k-- {
           dp[i] += dp[j] * dp[k]
           j++;
         }
       }
   }
   fmt.Printf("%d", dp[N])
}
