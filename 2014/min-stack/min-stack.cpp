class MinStack {
  public:
        void push(int x) {
                  st.push(x);
                          if (minSt.empty() || minSt.top().first > x)
                                        minSt.push(make_pair(x, 1));
                                  else if (minSt.top().first == x)
                                                ++minSt.top().second;
                                      }

            void pop() {
                      if (st.top() == minSt.top().first && --minSt.top().second == 0)
                                        minSt.pop();
                              st.pop();
                                  }

                int top() {
                          return st.top();
                              }

                    int getMin() {
                              return minSt.top().first;
                                  }
                        stack<int> st;
                            stack<pair<int, int> > minSt;
};
