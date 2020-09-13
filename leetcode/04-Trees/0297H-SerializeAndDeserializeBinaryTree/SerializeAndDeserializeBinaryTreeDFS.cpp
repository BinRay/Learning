#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        rserialize( root, str );
        str = str.substr(0, str.size()-1 );
        return str;
    }
    
    // rserialize
    void rserialize( TreeNode* root, string &str ){
        if ( root == NULL ){
            str.append("null,");
            return;
        }
        
        str.append( to_string(root->val) + "," );
        rserialize( root -> left, str );
        rserialize( root -> right, str );
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ( data.size() == 0 ){
            return NULL;
        }
        TreeNode* root;
        vector<string> v;
        split( data, v );
        vector<string>::iterator it = v.begin();
        root = rdeserialize( data, it );
        return root;
    }
    
    TreeNode* rdeserialize( string &data, vector<string>::iterator& it ){
        if ( *it == "null"){
            it++;
            return NULL;
        }

        TreeNode* cur_prt = new TreeNode(stoi(*it));
        it++;

        cur_prt->left = rdeserialize( data, it );
        cur_prt->right = rdeserialize( data, it );

        return cur_prt;
    }

    static void split ( const string& data, vector<string>& tokens, string delimter = "," ){
        string::size_type last_pos = data.find_first_not_of( delimter, 0 );
        string::size_type delim_pos = data.find_first_of( delimter, last_pos );
        while ( last_pos != string::npos || delim_pos != string::npos ){
            tokens.push_back( data.substr( last_pos, delim_pos-last_pos ));
            last_pos = data.find_first_not_of( delimter, delim_pos );
            delim_pos = data.find_first_of( delimter, last_pos );
        }
    }
};

int main( int argc, char** argv ){
    TreeNode node1( 1 );
    TreeNode node2( 2 );
    TreeNode node3( 3 );
    TreeNode node4( 4 );
    TreeNode node5( 5 );

    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;

    Codec c;
    // data: 1,2,null,null,3,4,null,null,5,null,null
    string data = c.serialize( &node1 );
    c.deserialize(data);

}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));