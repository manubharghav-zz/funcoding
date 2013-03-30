/*
PROG: easyprob
LANG: JAVA
*/
// The two standard imports that cover most useful classes.
import java.util.*;
import java.io.*;
// import java.math.*; // BigInteger
public class easyprob // always use the problem name here
{
// throw an IOException here so there is no need to handle errors later
public static void main(String[] args) throws IOException
{
// These two classes are rather fast for input and output.
BufferedReader input = new BufferedReader(new FileReader("easyprob.in"));
PrintWriter output = new PrintWriter(new BufferedWriter(new FileWriter("easyprob.out")));
int N = Integer.parseInt(input.readLine());
int sum = 0;
for(int i = 0; i < N; i++)
{
int next = Integer.parseInt(input.readLine());
sum += next;
}
output.println(sum);
output.close();
System.exit(0);
}
}