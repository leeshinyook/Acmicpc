using System;

namespace BOJ
{
  class MainClass
  {
    static char[,] arr = new char[31, 31];
    static bool nullSpace = false;
    public static void Main(string[] args)
    {
     
      int N;
      N = int.Parse(Console.ReadLine());
      for(int i = 1; i <= N; i++) {
        string line = Console.ReadLine();
        for (int j = 0; j < N; j++) {
          arr[i, j + 1] = line[j];
          if (line[j].Equals('.')) nullSpace = true;
        }
      }
      if(!nullSpace)
      {
        Console.WriteLine("ongoing");
        return;
      }
      for(int i = 1; i <= N; i++)
      {
        for(int j = 1; j <= N; j++)
        {
          if(search(i, j)) {
            Console.WriteLine(arr[i, j]);
            return;
          }
        }
      }
      Console.Write("ongoing");
      return;
    }
    public static bool search(int x, int y) {
      char num = arr[x, y];
      if (num.Equals('.')) return false;
      if(num.Equals(arr[x + 1, y]) && num.Equals(arr[x + 2, y])) {
        return true;
      }
      if(num.Equals(arr[x, y + 1]) && num.Equals(arr[x, y + 2]))
      {
        return true;
      }
      if(num.Equals(arr[x + 1, y + 1]) && num.Equals(arr[x + 2, y + 2]))
      {
        return true;
      }
      if(num.Equals(arr[x + 1, y - 1]) && num.Equals(arr[x + 2, y - 2]))
      {
        return true;
      }
      return false;
    }
  }
}

