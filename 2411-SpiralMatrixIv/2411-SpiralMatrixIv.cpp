// Last updated: 4/24/2026, 10:06:35 PM
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        
        ListNode* temp = head;
        
        while (temp != nullptr) {
            // Fill top row (left to right)
            for (int i = left; i <= right && temp != nullptr; ++i) {
                matrix[top][i] = temp->val;
                temp = temp->next;
            }
            top++; // Move top boundary down
            
            // Fill right column (top to bottom)
            for (int i = top; i <= bottom && temp != nullptr; ++i) {
                matrix[i][right] = temp->val;
                temp = temp->next;
            }
            right--; // Move right boundary left
            
            // Fill bottom row (right to left)
            for (int i = right; i >= left && temp != nullptr; --i) {
                matrix[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--; // Move bottom boundary up
            
            // Fill left column (bottom to top)
            for (int i = bottom; i >= top && temp != nullptr; --i) {
                matrix[i][left] = temp->val;
                temp = temp->next;
            }
            left++; // Move left boundary right
        }
        
        return matrix;
    }
};
