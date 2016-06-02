/**
Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()==0) return 0;
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int> count;
            int countzero=0;
            int currentmax=0;
            int countsame=0;
            for(int j=i+1;j<points.size();j++){
                if(points[j].x-points[i].x==0)
                 {if (++countzero && points[j].y==points[i].y && ++countsame) ;}
                else 
                {   double index=double(points[j].y-points[i].y)/double(points[j].x-points[i].x);
                    count[index]++;
                    if(currentmax<count[index]) currentmax=count[index];
                }
            }
            currentmax+=countsame;
            if(currentmax<countzero) currentmax=countzero;
            if(res<currentmax) res=currentmax;
        }
        return res+1;
    }
};
