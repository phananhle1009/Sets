//========================================================
// Phan Anh Le 
// test_set.cpp
// January 2024
// This file contains the test cases of the
// Set class.
//========================================================

#include <iostream>
#include "set.cpp"
#include <random>
#include <cstdlib>

void test_insert() {
//integer
    try {
        Set<int> s;
        s.insert(2);
        string set_str = s.to_string();
        if (s.to_string() != "2") {
            cout << "Incorrect insert result. Expected 2 but got : " << set_str << endl;
        }
        s.insert(3);
        s.insert(-7);
        set_str = s.to_string();
        if (s.to_string() != "-7 3 2") {
            cout << "Incorrect insert result. Expected -7 3 2 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
// float
    try {
        Set<float> s1;
        s1.insert(0.12);
        string set_str = s1.to_string();
        if (s1.to_string() != "0.12") {
            cout << "Incorrect insert result. Expected 0.12 but got : " << set_str << endl;
        }
        s1.insert(6.2);
        s1.insert(-9.8);
        set_str = s1.to_string();
        if (s1.to_string() != "-9.8 6.2 0.12") {
            cout << "Incorrect insert result. Expected 9.8 6.2 0.12 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
//charater
    try {
        Set<char> s;
        s.insert('X');
        s.insert('Y');
        s.insert('Z');
        string set_str = s.to_string();
        if (set_str != "Z Y X") {
            cout << "Incorrect insert result for char. Expected Z Y X but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting char into set : " << e.what() << endl;
    }

//string
    try {
        Set<string> s;
        s.insert("basketball");
        s.insert("computer");
        s.insert("c++");
        string set_str = s.to_string();
        if (set_str != "c++ computer basketball") {
            cout << "Incorrect insert result for string. Expected c++ computer basketball but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting string into set : " << e.what() << endl;
    }
}

void test_remove() {
    //int
    try {
        Set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(3);
        string set_str = s.to_string();
        if (s.to_string() != "4 2 1") {
            cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << endl;
        }
        s.remove(0);
        set_str = s.to_string();
        if(s.to_string() != "4 2 1") {
            cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }

    //float
     try {
        Set<float> s;
        s.insert(4.2);
        s.insert(2.3);
        s.insert(-8.7);
        s.remove( 7.1);
        string set_str = s.to_string();
        if (set_str != "-8.7 2.3 4.2") {
            cout << "Incorrect insert result for float. Expected -8.7 2.3 4.2 but got : " << set_str << endl;
        }
        s.remove(4.2);
        set_str = s.to_string();
        if(s.to_string() != "-8.7 2.3") {
            cout << "Incorrect remove result. Expected -8.7 2.3 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting float into set : " << e.what() << endl;
    }

    //char
    try {
        Set<char> s;
        s.insert('a');
        s.insert('b');
        s.insert('c');
        s.remove('c');
        string set_str = s.to_string();
        if (set_str != "b a") {
            cout << "Incorrect remove result for char. Expected b a but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing char from set : " << e.what() << endl;
    }

    //string
    try {
        Set<string> s;
        s.insert("class");
        s.insert("python");
        s.insert("java");
        s.remove("python");
        string set_str = s.to_string();
        if (set_str != "java class") {
            cout << "Incorrect remove result for string. Expected java class but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing string from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6);
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
        s.remove(4);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
        s.insert(10); 
        s.insert(33.3); 
        c = s.cardinality(); 
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;  
        }     
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    try {
        Set<int> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(1);
        s.remove(3);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
//integer
    try {
        Set<int> s;
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.remove(3);
        if(s.contains(0)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(1)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }
        if (s.contains(3)){
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in se : " << e.what() << endl;
    }

//string
    try {
        Set<string> s;
        s.insert("hello");
        s.insert("bye");
        if(!s.contains("hello")) {
            cout << "Incorrectly identified 'hello' as NOT in the set " << s.to_string() << endl;
        }
        if(s.contains("party")) {
            cout << "Incorrectly identified 'party' as in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if string contained in set : " << e.what() << endl;
    }

//float 
    try {
        Set<string> s;
        s.insert("4.2");
        s.insert("2.1");
        if(!s.contains("2.1")) {
            cout << "Incorrectly identified '2.1' as NOT in the set " << s.to_string() << endl;
        }
        if(s.contains("0.3")) {
            cout << "Incorrectly identified '0.3' as in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if string contained in set : " << e.what() << endl;
    }
}


void test_equality() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert(2);
        t.insert(3);
        t.insert(1);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.remove(3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
//integer
    try {
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(6);
        t.insert(4);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(4);
        s.insert(6);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(19);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(12);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }

        s.remove(4);
        s.remove(6);
        s.remove(12);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s+t).to_string();
        if(set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(3);
        s.insert(2);
        t.insert(2);
        t.insert(3);
        set_str = (s+t).to_string();
        if(set_str != "2 3") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "2 3 1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(2);
        s.insert(3);
        t.insert(1);
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert(3);
        t.insert(2);
        set_str = (s&t).to_string();
        if(set_str != "2 3") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 3 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(3);
        s.insert(1);
        t.insert(8);
        set_str = (t-s).to_string();
        if(set_str != "8") {
            cout << "Set " << t.to_string() << " \\ Set " << s.to_string() << " was expected to be 8 set but instead got : " << set_str << endl;
        }
        t.insert(3);
        t.insert(1);
        set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void time_test() {
    Set<int> S;
    // TO-DO: generate large set
    for (int i = 0; i < 10000; ++i)
    {
        S.insert(rand() % 10000);
    }
    Set<int> T;

    // TO-DO: generate large set
            for (int i = 0; i < 10000; ++i)
    {
        T.insert(rand() % 10000);
    }
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    S.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.remove(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.cardinality();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    S.empty();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    val = rand()%100000;
    begin = std::chrono::high_resolution_clock::now();
    bool r = S.contains(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S==T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S<=T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    Set<int> U = (S+T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S&T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S-T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();

    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}
