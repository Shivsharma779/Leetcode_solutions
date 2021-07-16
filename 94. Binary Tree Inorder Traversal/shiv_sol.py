class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return 
        else:
            ans = []
            x = self.inorderTraversal(root.left)
            y = self.inorderTraversal(root.right)
            
            if  x != None:
                ans += x
            ans +=[root.val]
            if y!= None:
                ans += self.inorderTraversal(root.right)
            return ans
