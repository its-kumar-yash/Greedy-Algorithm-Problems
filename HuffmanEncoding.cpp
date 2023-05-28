// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character 
//S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder 
//traversal of the tree.
// Note: While merging if two nodes have the same value, 
//then the node which occurs at first will be taken on the left of 
//Binary Tree and the other one to the right, otherwise Node with less value will be taken on the 
//left of the subtree and other one to the right.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Node Class
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


class Solution
{
	public:
	    void traverse(Node* root, vector<string> &ans, string temp){
	        
	        if(root == NULL){
	            return;
	        }
	        //leaf node
	        if(root->left == NULL && root->right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        
	        traverse(root->left, ans, temp + '0');
	        traverse(root->right, ans, temp + '1');
	        
	        
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    //create min Heap
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    //push all frequency into min heap
		    for(auto i : f){
		        Node* temp = new Node(i);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1){
		        //pop two element
		        Node* leftChild = pq.top();
		        pq.pop();
		        Node* rightChild = pq.top();
		        pq.pop();
		        
		        //create root node using there sum
		        int sum = leftChild->data + rightChild->data;
		        
		        Node* currRoot = new Node(sum);
		        currRoot->left = leftChild;
		        currRoot->right = rightChild;
		        
		        //again push the currRoot into min heap
		        pq.push(currRoot);
		    }
		    
		    //when the loop overs the minheap contains one node
		    //that is Root Node
		    Node* root = pq.top();
		    pq.pop();
		       
		    
		    //finding encoding string for each leaf node
		    vector<string> ans;
		    string temp = "";
		    traverse(root, ans, temp);
		    
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends