//
// Created by lbinr on 2020/6/22.
//

#include <queue>
#include <iostream>
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

        queue<TreeNode*> q;
        q.push( root );

        string str;

        while ( !q.empty() ){
            TreeNode* cur_ptr = q.front();
            q.pop();

            if ( cur_ptr == NULL ){
                str += "null,";
            } else {
                str += to_string( cur_ptr->val ) + ",";
                q.push( cur_ptr -> left );
                q.push( cur_ptr -> right );
            }
        }
        str = str.substr(0, str.size()-1 );
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        split( data, v );
        if ( v.empty() ){
            return NULL;
        }

        vector<string>::iterator it = v.begin();
        if ( *it == "null" ){
            return NULL;
        }

        // 这里的队列只存非null值
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(*it));
        q.push( root );
        it++;

        TreeNode* cur_ptr;
        while ( !q.empty() ){
            cur_ptr = q.front();
            q.pop();
            if ( *it != "null" ){
                cur_ptr->left = new TreeNode(stoi(*it));
                q.push( cur_ptr->left );
            }
            it++;

            if ( *it != "null" ){
                cur_ptr->right = new TreeNode(stoi(*it));
                q.push( cur_ptr->right );
            }
            it++;
        }
        return root;
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
    string data = c.serialize( &node1 );
    vector<string> tokens;
    //data: 1,2,3,null,null,4,5,null,null,null,null
    cout << data << endl;
    c.split( data, tokens, ",");
    for ( vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++ ){
        cout << *it << endl;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));