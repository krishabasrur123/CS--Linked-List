

#include "Map.h"
#include <string>
#include <iostream>
#include <cassert>


using namespace std;

int main()
{
// Empty Map Testcases
    Map m1;  // new dummy head alloted
    Map m2 = Map();   // new dummy head alloted 
    //testcase set #1 - Check whether or not the default constructor makes an empty 0 size map
    assert(m1.size() == 0 && m2.size() == 0 && m1.empty() == true && m2.empty() == true);
    // testcase  set #2 - Check whether the erase, get functions, update, contains function and swap works
    KeyType emptryString = "";
    ValueType dummyVal = 9.9;
    assert(m2.erase("")==false); // erase shouldn't work on empty list
    assert(m2.erase("Krisha")==false);
    assert(m2.get(emptryString, dummyVal)==false);
    assert(m2.get(0,emptryString,dummyVal) == false);
    assert(m2.get("Krisha", dummyVal) == false);
    KeyType name = "krisha";
    assert(m2.get(0, name, dummyVal) == false);
    assert(m2.update("",5)==false);
    assert(m2.contains("")==false);
    m1.swap(m2);
   (m1.erase("")==false);

   // testcase set # 3  checking whether inserts and insert or update functions corrctly insert in order
   assert (m1.insert("Apple", 1.2)==true);
   assert(m1.insertOrUpdate("Dog", 4.5)==true);
   assert(m1.insertOrUpdate("Cat", 3.4) == true);
   assert(m1.insert("Banana", 2.3) == true);
   assert(m1.insert("banana", 2.956) == true);
   
  assert( m1.insert("Banana", 3.538)==false);// should not insert a key that is already in the list
   m1.insertOrUpdate("", 3.355);
   assert(m1.size() == 6 && m1.empty() == false);// checks size of the new inserted list
   KeyType key;
   ValueType val;
   //  testcase set #4 checking if get function works and insert has ordered the map correctly in various positions of list (begginging, mid, end)
  assert(m1.get(0,key,val)==true && key=="" && val == 3.355);
  assert(m1.get(1, key, val) == true && key == "Apple" && val == 1.2);
  assert(m1.get(2, key, val) == true && key == "Banana" && val == 2.3);
  assert(m1.get(3, key, val) == true && key == "Cat" && val == 3.4);
  assert(m1.get(4, key, val) == true && key == "Dog" && val == 4.5);
  assert(m1.get(5, key, val) == true && key == "banana" && val == 2.956);

  // subpart of test case #4 checking whether get functions work with incorrect values
  assert(m1.get(-1, key, val) == false);
  assert(m1.get("blah", val) == false);
  assert(m1.get(6, key, val) == false);
  assert(m1.get(150, key, val) == false);

  // test Case set #5 more insert, insertorupdate and update cases
  assert(m1.insert("", 3.35)==false);// shouldn't insert a key already in map
  assert(m1.update("apple", 7.8)==false); // shouldn't update a key not in the map
  assert(m1.update("Apple", 1.22) == true);
  assert(m1.insertOrUpdate("Dog", 4.55) == true);
  assert(m1.insertOrUpdate("Cat", 3.44) == true);
  assert(m1.update("Catt", 3.44) == false);// shouldn't update as key is not found
  m1.get("Apple", val);
  assert(m1.insertOrUpdate("", val) == true); // should update map to have two different keys with equal values
  
  val=9.9999;
 assert(m1.get("", val)==true&& val==1.22);
  assert(m1.update("Banana", 2.33) == true);
  assert(m1.insertOrUpdate("banana",5.66)==true);
 
 //test case set #6  check whether get function still works when keys are updated in various positions of list (begginging, mid, end)
  assert(m1.get(0, key, val) == true && key == "" && val == 1.22);
  assert(m1.get(1, key, val) == true && key == "Apple" && val == 1.22);
  assert(m1.get(2, key, val) == true && key == "Banana" && val == 2.33);
  assert(m1.get(3, key, val) == true && key == "Cat" && val == 3.44);
  assert(m1.get(4, key, val) == true && key == "Dog" && val == 4.55);
  assert(m1.get(5, key, val) == true && key == "banana" && val == 5.66);
 

  // test case set #7 check whether functions still work if a map that is filled (there shouldn't be any limit)

  assert(m2.insert("c", 9) == true && m2.size() == 1);
  string a = "";
  for (int i = 0; i < (150); i++) {
      a = a + "a";
      m2.insert(a, i);
  }
  assert(m2.size() == 151); // check if size is max
  assert(m2.insert("", 8.245) == true && m2.size() == 152); // check if function adds a key
  assert(m2.get(0,key,val)==true && val==8.245 && key==""); // check if the key is correctly sorted in the list beggining
  assert(m2.get(3, key, val) == true && val == 2 && key == "aaa"); // check if key is correctly sorted in the middle
  assert(m2.get(151, key, val) == true && val == 9 && key=="c"); // check if key is correctly sorted at the end
  assert(m2.insert("aaaaaa",3) == false); // check if insert shouldn't insert a key already in map
  assert(m2.insertOrUpdate("aaaaaa", 9.9) == true && m2.get(6,key,val)==true && key=="aaaaaa" && val==9.9); //update should work in mid list
  assert(m2.update("Krisha", 3) == false); // update shouldn't update a key nowhere in the map
  // more update tests
  assert(m2.update("a", 3) == true && m2.get(1,key,val)==true&& val==3);
  assert(m2.update("aaaa", 9) == true && m2.get(4, key, val) == true && val == 9);
  assert(m2.insertOrUpdate("c", 10) == true && m2.get(151, key, val) == true && key == "c" && val == 10);
  assert(m2.erase("a") == true); // erase function in mid list
  assert(m2.get(1, key, val) == true && val == 1 && key == "aa"); 
  assert(m2.erase("a") == false);
  assert(m2.get("a",val)==false && val==1 ); 
  assert(m2.get("", val) == true && val == 8.245);
  assert(m2.erase("") == true); // erase function in beginning
  assert(m2.get(0, key, val) == true && val == 1 && key == "aa" && m2.size()==150);
  assert(m2.erase("") == false);
  assert(m2.get("", val) == false && val == 1);

  assert(m2.erase("c") == true); // erase function in end
  assert(m2.get(148, key, val) == true && val == 149 && m2.size() == 149);
  assert(m2.erase("") == false);
  assert(m2.get("", val) == false && val == 149);

  
  // test case # set 7 working with one element list and two element list, along with testing copy constructor, swap function
Map m3;
assert(m3.insert("hello", 8.88) == true && m3.size() == 1);
assert(m3.get(0,key,val)==true && key=="hello" && val==8.88);
val=9;
assert(m3.get(key, val) == true && key == "hello" && val == 8.88);
assert(m3.get(1, key, val) == false && key == "hello" && val == 8.88);

Map m4= m3; 
assert(m4.size() == 1 && m4.get(0, key, val) == true && key == "hello" && val == 8.88);

m3.erase("hello");
key="yoo";
val=100;
assert (m3.size()==0 && m3.get(0,key,val)==false && key == "yoo" && val == 100);
m4.insertOrUpdate("b", 999);

m4.swap(m3);
assert(m3.get(1, key, val) == true && key == "hello" && val == 8.88);
assert(m3.get(0, key, val) == true && key == "b" && val == 999 && m3.size()==2);
assert(m3.erase("")== false && m3.erase("hello")==true && m3.size()==1);


// swap function test

m1.swap(m2);
assert(m2.size()==6);
assert(m2.get(0, key, val) == true && key == "" && val == 1.22);
assert(m2.get(1, key, val) == true && key == "Apple" && val == 1.22);
assert(m2.get(2, key, val) == true && key == "Banana" && val == 2.33);
assert(m2.get(3, key, val) == true && key == "Cat" && val == 3.44);
assert(m2.get(4, key, val) == true && key == "Dog" && val == 4.55);
assert(m2.get(5, key, val) == true && key == "banana" && val == 5.66);

assert(m1.size()==149);
assert(m1.get(0,key,val)==true&& key=="aa" && val==1);
assert(m1.get(148, key, val) == true && val == 149);

// test case set #8 testing assignment operater

m3=m2;
// m2 should be unchanged
assert(m2.size() == 6);
assert(m2.get(0, key, val) == true && key == "" && val == 1.22);
assert(m2.get(1, key, val) == true && key == "Apple" && val == 1.22);
assert(m2.get(2, key, val) == true && key == "Banana" && val == 2.33);
assert(m2.get(3, key, val) == true && key == "Cat" && val == 3.44);
assert(m2.get(4, key, val) == true && key == "Dog" && val == 4.55);
assert(m2.get(5, key, val) == true && key == "banana" && val == 5.66);

// m3 should be changed
assert(m3.size() == 6);
assert(m3.get(0, key, val) == true && key == "" && val == 1.22);
assert(m3.get(1, key, val) == true && key == "Apple" && val == 1.22);
assert(m3.get(2, key, val) == true && key == "Banana" && val == 2.33);
assert(m3.get(3, key, val) == true && key == "Cat" && val == 3.44);
assert(m3.get(4, key, val) == true && key == "Dog" && val == 4.55);
assert(m3.get(5, key, val) == true && key == "banana" && val == 5.66);


m2=m2; // testing an assignment to itself

// m2 should be unchanged
assert(m2.size() == 6);
assert(m2.get(0, key, val) == true && key == "" && val == 1.22);
assert(m2.get(1, key, val) == true && key == "Apple" && val == 1.22);
assert(m2.get(2, key, val) == true && key == "Banana" && val == 2.33);
assert(m2.get(3, key, val) == true && key == "Cat" && val == 3.44);
assert(m2.get(4, key, val) == true && key == "Dog" && val == 4.55);
assert(m2.get(5, key, val) == true && key == "banana" && val == 5.66);


// #testcase set #8 merge function testing
Map m5;
m5.insert("Fred",123);
m5.insert("Ethel", 456);
m5.insert("Lucy", 789);

Map test;
Map test1;
Map mm;
assert(merge(test,test1,mm)==true);// check if empty map can be merged

Map m6=m5;
assert(merge(test,m6,test1)==true); // should return true with an empty map
assert(merge(m6,m5, test)==true);// should return true as maps are the same
assert(test.size()==3); // check if the test map is same as m5 or m6, but not a repeat of both
assert(test.get(0, key, val) == true && key == "Ethel" && val == 456);
assert(test.get(1, key, val) == true && key == "Fred" && val == 123);
assert(test.get(2, key, val) == true && key == "Lucy" && val == 789);




// check with keys with different values, if  same key and same value, should pass
Map m7;
m7.insert("Lucy" , 789 );
m7.insert("Gicky", 321);
assert(merge(m5,m7,test)==true);

assert(test.size()==4);
assert(test.get(0,key,val)==true && key=="Ethel"&& val==456);
assert(test.get(1, key, val) == true && key == "Fred" && val == 123);
assert(test.get(3, key, val) == true && key == "Lucy" && val == 789);
assert(test.get(2, key, val) == true && key == "Gicky" && val == 321);

Map mmr;
Map mm2;
Map mm3;

assert(mmr.insert("Box", 23) && mmr.insert("child", 22) && mmr.insert("Jack", 32));
assert(mm2.insert("Jack", 56) && mm2.insert("dad", 4) && mm2.insert("mom", 5) && mm2.insert("child", 57));
assert(mm3.insert("Jack",57));
assert(!merge(mm2,mm3,mmr));
assert(mmr.size()==3);
assert(mmr.get(0, key, val) == true && key == "child" && val == 57);
assert(mmr.get(1, key, val) == true && key == "dad" && val ==4);
assert(mmr.get(2, key, val) == true && key == "mom" && val == 5);

// Map Alliasing
merge(mm2, mm2, mm2);
assert(mm2.size() == 4);
assert(mm2.get(0, key, val) == true && key == "Jack" && val == 56);
assert(mm2.get(2, key, val) == true && key == "dad" && val == 4);
assert(mm2.get(3, key, val) == true && key == "mom" && val == 5);

mmr.insert("Krisha",78);
merge(mm2,mmr,mm2);
assert(mm2.size() == 5);
assert(mm2.get(0, key, val) == true && key == "Jack" && val == 56);
assert(mm2.get(1, key, val) == true && key == "Krisha" && val == 78);
assert(mm2.get(3, key, val) == true && key == "dad" && val == 4);
assert(mm2.get(4, key, val) == true && key == "mom" && val == 5);
assert(mm2.get(2, key, val) == true && key == "child" && val == 57);


// testing to see whether same keys with diff values do not pass into the result map (test)
Map m8;
m8.insert("Fred", 123);
m8.insert("Ethel", 456);
m8.insert("Ricky",321);
m8.insert("Lucy", 456);
assert(merge(m5, m8, test) == false);
assert(test.size()==3);
assert(test.get(0, key, val) == true && key == "Ethel" && val == 456);
assert(test.get(1, key, val) == true && key == "Fred" && val == 123);
assert(test.get(2, key, val) == true && key == "Ricky" && val == 321);

test.insert("Lucy",789);

// #test case  set #9  reassign testing
Map m9;
m9.insert("akey", 9); // test if function doesn't work with a single key
reassign(m9, m7);
assert(m7.size()==1 && m7.get(0,key,val)==true && key=="akey" && val==9);
// test for two key reassigns
m9.insertOrUpdate("a",45);
reassign(m9, m7);
assert(m7.size() == 2 && m7.get(1, key, val) == true && key == "akey" && val == 45 );
assert(m7.get(0, key, val) == true && key == "a" && val == 9);
reassign(test,m9);

// testing for multiple keys with different values
assert(m9.size() == 4);
assert(m9.get(0, key, val) == true && key == "Ethel" && val == 123);
assert(m9.get(1, key, val) == true && key == "Fred" && val == 789);
assert(m9.get(2, key, val) == true && key == "Lucy" && val == 321);
assert(m9.get(3, key, val) == true && key == "Ricky" && val == 456);

Map m11;
// testing for empty map
reassign(m11,test);
assert(test.size()==0);
// testing for a map with diff keys with similar values, should still function and rematch
m11.insert("Fred", 123);
m11.insert("Ethel", 456);
m11.insert("Lucy", 456);
reassign(m11,test);
assert(test.size() == 3);
assert(test.get(0, key, val) == true && key == "Ethel" && val == 123);
assert(test.get(1, key, val) == true && key == "Fred" && val == 456);
assert(test.get(2, key, val) == true && key == "Lucy" && val == 456);


// Note the destructor was tested where we printed a statement whenever a new map was being created, and then printing out an statement in the destructor and erase whenever an object got deleted. The number of statements in the destructor matched the number of times we allocated with new in our map

cerr<<"All tests passed"<<endl;





}






