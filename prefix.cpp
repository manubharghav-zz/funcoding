/*
ID: manubha1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std;


set<string> prefix;
vector<int> pos;
vector<bool> pos1;

int max_size;


int no_zeros(string s){
	int i=0;
	for(i=0;i<s.length();i++){
		if(s[i]!='0'){
			break;
		}
	}
	return i;
}

bool check(string s){
	// cout << s << "  " << no_zeros(s) << endl;s
	if(no_zeros(s)>=max_size){
		return true;
	}
	else{
		return false;
	}
}


int main(){

	ifstream fin("prefix.in");
	ofstream fout("prefix.out");


	string s;
	fin >> s;
	max_size = s.length();
	while(s!="."){
		if(s.length()>max_size){max_size = s.length();}
		prefix.insert(s);
		fin >> s;
	}

	char seq;
	string buffer=""; //always a string of size 10;
	string possible="c";
	int count=0;
	while((fin>>seq)!=NULL){

		if(check(possible)){fout << (count-(no_zeros(possible))) << endl;return 0;}
		if(buffer.length()>11){
			buffer.erase(buffer.size()-1);
			buffer = seq + buffer;
			possible.erase(possible.size()-1);
			possible = "0"+possible;
		}
		else{
			buffer=seq + buffer;
			possible = "0"+possible;
		}

		count++;

		set<string>::iterator it = prefix.begin();
		bool match =false;
		for(it=prefix.begin();it!=prefix.end();it++){
			// do the first match and if the next charector from possible is also 1 then break else continue;

			string pref = *it;
			int preflen = pref.length();
			bool match1=true;
			int q1=0;
			for(q1=0;q1<preflen;q1++){
				if(buffer[q1]!=pref[preflen-1-q1]){
					match1 = false;
					break;
				}
			}


			if(match1==true && (possible[q1]=='1'|| possible[q1]=='c')){
				match=true;
				break;
			}


		}
		if(match){
			possible[0]='1';
		}

	}


	
//	cout << possible << "  " <<i << "  " <<count << endl;
	// cout << "rached here" << endl;
	fout << (count - no_zeros(possible)) << endl;




}



// The basic tool to use here is dynamic programming. For each prefix of the sequence, you know that it is expressible in terms of the primitives if and only if you can find some shorter expressible prefix such that the sequence between the two prefixes is a primitive. Thus, you can check each primitive and see if it matches the end of a prefix and whether the prefix before that primitive (the pre-prefix, if you would) is expressible.

// This can be turned-around to get something that is simpler to code. For each prefix that is expressible, determine which primitives match the sequence beginning at that location, and mark the prefix plus the primitive as expressible, if it does.

// In the worst case, you have to check each prefix starting at each location. There are at most 200 prefixes of length 10 to check at each of 200,000 locations, for a total of 400,000,000 operations. This is a little higher than the standard number you would expect to be able to do in 5 seconds, but it is a very small operation (two array look-ups and a character comparison), and an over-estimate on how bad it can actually get.

// #include <stdio.h>

// /* maximum number of primitives */
// #define MAXP 200
// /* maximum length of a primitive */
// #define MAXL 10

// char prim[MAXP+1][MAXL+1]; /* primitives */
// int nump;                  /* number of primitives */

// int start[200001];         /* is this prefix of the sequence expressible? */
// char data[200000];         /* the sequence */
// int ndata;                 /* length of the sequence */

// int main(int argc, char **argv)
//  {
//   FILE *fout, *fin;
//   int best;
//   int lv, lv2, lv3;

//   if ((fin = fopen("prim.in", "r")) == NULL)
//    {
//     perror ("fopen fin");
//       exit(1);
//    }
//   if ((fout = fopen("prim.out", "w")) == NULL)
//    {
//     perror ("fopen fout");
//     exit(1);
//    }

//   /* read in primitives */
//   while (1)
//    {
//     fscanf (fin, "%s", prim[nump]);
//     if (prim[nump][0] != '.') nump++;
//     else break;
//    }

//   /* read in string, one line at a time */
//   ndata = 0;
//   while (fscanf (fin, "%s", data+ndata) == 1)
//     ndata += strlen(data+ndata);

//   start[0] = 1;
//   best = 0;
//   for (lv = 0; lv < ndata; lv++)
//     if (start[lv]) 
//      { /* for each expressible prefix */
//       best = lv; /* we found a longer expressible prefix! */
//       /* for each primitive, determine the the sequence starting at
//          this location matches it */
//       for (lv2 = 0; lv2 < nump; lv2++)
//        {
//         for (lv3 = 0; lv + lv3 < ndata &&  prim[lv2][lv3] &&
// 	    prim[lv2][lv3] == data[lv+lv3]; lv3++)
//           ;
// 	if (!prim[lv2][lv3])   /* it matched! */
// 	  start[lv + lv3] = 1; /* so the expanded prefix is also expressive */
//        }
//      } 

//   /* see if the entire sequence is expressible */
//   if (start[ndata]) best = ndata; 

//   fprintf (fout, "%i\n", best);
//   return 0;
//  }
// Additional Analysis from Marian Dvorsky in Slovakia

// After the main idea is clear, we can think about an improvements. First of all we notice that a trick can reduce space complexity from O(n) (where n is 200,000 - length of sequence) to O(maxl) (where maxl is 10, the length of the longest word in dictionary), but that requires an "opposite" method to the one Hal used in his program. For all prefixes of length n (n grows in increasing order), we check if they are expressible in terms of primitives.

// The second improvement is the check for whether the end (suffix) of prefix is primitive. This can be also done in O(maxl) with a structure called a `trie'. We will have a tree in which every node represents some word (or prefix of some word) in a dictionary and edges represent characters. The root of the tree represents an empty word.

// If we walk from root to some node `i' and write down characters on edges we've used, we get some word `v'. The node `i' then represents word `v'. Moreover if word `v' is in dictionary, we will remember it in that node (with some boolean variable).

// Finally, when we learn that the last maxl prefixes aren't expressible, then no more prefixes are, so we can exit immediately.

// In the worst case, we will, for every prefix (200,000), check a word of length maxl (10), for a total of 2,000,000 `operations'.

// (* maximum length of primitive *)
// const MAXL=20;

// type pnode=^node;
//      node=record
//             next:array['A'..'Z'] of pnode;
//             isthere:boolean;
//           end;

// var trie:pnode;     (* dictionary *)
//     p:pointer;
//     fin,fout:text;

// (* read space separated word from file *)
// function readword:string;
// var s:string;
//     ch:char;
// begin
//   read(fin,ch);
//   while (not (ch in ['A'..'Z','.'])) do
//     read(fin,ch);
//   s:='';
//   while (ch in ['A'..'Z','.']) do
//   begin
//     s:=s+ch;
//     read(fin,ch);
//   end;
//   readword:=s;
// end;

// (* read dictionary *)
// procedure readdict;
// var n,i,j,l:integer;
//     nod:pnode;
//     ch,ch2:char;
//     s:string;
// begin
//   new(trie);
//   for ch2:='A' to 'Z' do
//     trie^.next[ch2]:=nil;
//   trie^.isthere:=false;
//   s:=readword;
//   while s<>'.' do
//   begin
//     nod:=trie;
//     l:=length(s);
//     (* save word in reverse order *)
//     for j:=l downto 1 do
//     begin
//       ch:=s[j];
//       if nod^.next[ch]=nil then
//       begin
//         new(nod^.next[ch]);
//         for ch2:='A' to 'Z' do
//           nod^.next[ch]^.next[ch2]:=nil;
//         nod^.next[ch]^.isthere:=false;
// 		end;
//       nod:=nod^.next[ch];
//     end;
//     nod^.isthere:=true;
//     s:=readword;
//   end;
// end;

// procedure compute;
// var start:array[0..MAXL] of boolean; (* is this prefix (mod MAXL) expressible ? *)
//     data:array[0..MAXL] of char;     (* the sequence (mod MAXL) *)
//     i,k:integer;
//     ch:char;
//     nod:pnode;
//     max,cnt:longint;
// begin
//   start[0]:=true;
//   read(fin,ch);
//   data[0]:=#0; (* sentinel *)
//   i:=1;
//   max:=0; cnt:=1;
//   while not eof(fin) do
//   begin
//     if not (ch in ['A'..'Z']) then
// 	 begin
//       read(fin,ch);
//       continue;
// 	 end;
//     if i=MAXL then i:=0;  (* i:=i mod MAXL *)
//     k:=i;
//     data[i]:=ch;
//     start[i]:=false;
//     nod:=trie;
//     (* is there primitive at the and of current prefix ? *)
//     while nod<>nil do
//     begin
//       nod:=nod^.next[data[k]];
//       dec(k); if k<0 then k:=MAXL-1;
//       if start[k] and (nod<>nil) and nod^.isthere then
//       begin
//         (* we've found a primitive at the end of prefix and the rest is
//            expressible *)
// 		  start[i]:=true;
//         max:=cnt; break;
//       end;
//       if data[k]=#0 then break;
//     end;
//     read(fin,ch);

//     (* if last MAXL prefixes are not expressible, no other prefix can
// 	    be expressible *)
//     if cnt>max+MAXL then break;

//     inc(i); inc(cnt);
//   end;

//   (* write answer *)
//   assign(fout,'prefix.out');
//   rewrite(fout);
//   writeln(fout,max);
//   close(fout);
// end;

// begin
//   mark(p);
//   assign(fin,'prefix.in');
//   reset(fin);
//   readdict;
//   compute;
//   close(fin);
//   release(p);
// end.
