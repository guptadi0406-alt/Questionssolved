class Solution {
    public boolean isValid(String s) {
        
        Stack<String> st=new Stack();
        for(int i=0;i<s.length();i++){
            char a=s.charAt(i);
     
            if(!st.isEmpty() && ((a==')' && st.peek().equals("(")) || (a=='}' && st.peek().equals("{"))  ||  (a==']' && st.peek().equals("[")))){
                st.pop();
            }else{
                st.push(String.valueOf(a));
            }
        }

        if(st.isEmpty()) return true;
        return false;
    }
}