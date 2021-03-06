// https://leetcode.com/problems/ugly-number-ii/

// Method 0 (DP, O(n)):

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(1,1);
        int p2, p3, p5, next;
        p2 = p3 = p5 = 0;
        // keep 3 pointers to point to next number being multiplied from the previously generated ugly numbers list
        while(v.size() < n){
            if(2*v[p2] <= min(3*v[p3], 5*v[p5])) 
                next = 2*v[p2++];
            else if(3*v[p3] <= min(2*v[p2], 5*v[p5])) 
                next = 3*v[p3++];
            else 
                next = 5*v[p5++];
            if(next > v.back()) v.push_back(next);
        }
        return v.back();
    }
};

// O(nlogn) or O(n2):

// Method 1 (generation only unique elements):

class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n == 1) return 1;
        
        priority_queue<long long int, vector<long long int>, greater<long long int>> q;   // Min heap
        q.push(2); 
        q.push(3); 
        q.push(5); 
        long long int count = 1, min_ele;
        while(count<=n){
            count++;
            min_ele = q.top();
            q.pop();
                
            if(count == n){
                return min_ele;
            }
            
            // generating only unique elements by
            // multiplying factors only in ascending order
            if(min_ele%5 == 0){
                q.push(min_ele*5);
            } else if(min_ele%3 == 0){
                q.push(min_ele*3);
                q.push(min_ele*5);
            } else if(min_ele%2 == 0){
                q.push(min_ele*2);
                q.push(min_ele*3);
                q.push(min_ele*5);
            }
            
        }
        
        // will never reach here
        return -1;
    }
};

// Method 2 (ignoring repetitions):

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> q;   // Min heap
        q.push(1); 
        long long int count = 0, min_ele;
        while(count<=n){
            count++;
            min_ele = q.top();
            if(count == n){
                return min_ele;
            }
            // ignoring repetition
            while(!q.empty() and min_ele == q.top()){
                q.pop();
            } 
            q.push(min_ele*2);
            q.push(min_ele*3);
            q.push(min_ele*5);
        }
        
        // will never reach here
        return -1;
    }
};

// Method 3 (Set):

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> s;
        s.insert(1);
        long long int count = 0, min_ele;
        while(count<=n){
            count++;
            min_ele = *s.begin();
            s.erase(s.begin());
                
            if(count == n){
                return min_ele;
            }
            
            s.insert(min_ele*2);
            s.insert(min_ele*3);
            s.insert(min_ele*5);
        }
        
        // will never reach here
        return -1;
    }
};