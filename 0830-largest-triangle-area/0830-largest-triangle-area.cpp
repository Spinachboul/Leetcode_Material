class Solution {
private:
    double dist(int x1, int y1, int x2, int y2){
        return sqrt((x1-x2) * (x1-x2)  + (y1-y2) * (y1-y2));
    }
    bool isValid(double d1, double d2, double d3){
        return (d1 + d2 >= d3) || (d2 + d3 >= d1) || (d1 + d3 >= d2);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        int n = points.size();

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                for(int k=j+1 ; k<n ; k++){
                    int xi = points[i][0];
                    int xj = points[j][0];
                    int xk = points[k][0];
                    int yi = points[i][1];
                    int yj = points[j][1];
                    int yk = points[k][1];
                    double d1 = dist(xi, yi, xj, yj);
                    double d2 = dist(xj, yj, xk, yk);
                    double d3 = dist(xi, yi, xk, yk);

                    if(isValid(d1, d2, d3)){
                        double semi = (d1 + d2 + d3)/2;
                        double area = sqrt((semi) * (semi-d1) * (semi-d2) * (semi-d3));
                        ans = max(ans, area);
                    }

                }
            }
        }
        return ans;


        
    }
};