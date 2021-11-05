struct point_i{ int x, y; point_i(){} point_i(int xx, int yy) : x(xx), y(yy){}};
struct point
{
    double x, y; point(){} point(double xx, double yy){ x = xx; y = yy;}
    bool operator<(const point &b)const{ if(fabs(x-b.x)<EPS){return y < b.y;}
        else  return  x < b.x;
    }
    bool operator==(const point &b)const
    {
        if(fabs(x-b.x)<EPS && fabs(y-b.y)<EPS) return true; else  return false;
    }
};
double dist(point p1, point p2){ return hypot(p1.x-p2.x, p1.y-p2.y);}
point Rotate(point p, double ang){ ang = ang*PI/180.0; point ret;
ret.x = p.x*cos(ang) - p.y*sin(ang); ret.y = p.x*sin(ang) + p.y*cos(ang);
return ret;
}
struct line         // defination of line ax + by + c = 0 (where b = 1).
{
    double a, b, c; line(){} line(double aa, double bb, double cc){ a = aa; b = bb; c = cc;}
};
void pointsToLine(point p1, point p2, line &l)
{
    if(p1.x==p2.x){ l.a = 1, l.b = 0, l.c = -p1.x;}
    else{ l.a = -(double)(p1.y - p2.y)/(p1.x-p2.x); l.b = 1.0; l.c = -(double)(l.a*p1.x)-p1.y;}
    return ;
}
bool areParallel(line l1, line l2)
{
    if(fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS) return true; return false;
}
bool areSame(line l1, line l2)
{
    if(areParallel(l1, l2) && fabs(l1.c-l2.c)<EPS) return true; return false;
}
bool areIntersect(line l1, line l2, point &p)
{
    if(areParallel(l1, l2)) return false;
    else{ p.x = (l1.b*l2.c - l2.b*l1.c)/(l1.a*l2.b - l2.a*l1.b); p.y = (l2.a*l1.c - l1.a*l2.c)/(l1.a*l2.b - l2.a*l1.b); return true;}
}
struct vec
{
    double x, y; vec(){} vec(double xx, double yy) : x(xx), y(yy){}
};
vec toVec(point p1, point p2) { return vec(p2.x-p1.x, p2.y-p1.y);}
vec scale(vec v, double s){ return vec(v.x*s, v.y*s); }
point translate(point p, vec v) { return point(p.x+v.x, p.y+v.y);}
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }
double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }
double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

double angle(point a, point o, point b)
{
    vec oa = toVec(o,a); vec ob = toVec(o,b); return acos(dot(oa,ob)/(sqrt(norm_sq(oa))*sqrt(norm_sq(ob))));
}
bool ccw(point p, point q, point r) { return cross(toVec(p,q), toVec(p,r)) > 0.0; }
bool cw(point p, point q, point r) { return cross(toVec(p,q), toVec(p,r)) < 0.0; }
bool coLinear(point p, point q, point r) { return fabs(cross(toVec(p,q), toVec(p,r))) < EPS; }
bool lineSegmentIntersect(point p1, point p2, point p3, point p4)
{
    if(ccw(p1,p2,p3)!=ccw(p1,p2,p4) && ccw(p3,p4,p1)!=ccw(p3,p4,p2)) return true; else  return false;
}
void pointSlopeToLine(point p, double m, line &l) { l.a = -m; l.b = 1; l.c = m*p.x - p.y; return ; }
void closestPoint(line l, point p, point &ans)
{   if(fabs(l.b)<EPS){ ans.x = -(l.c); ans.y = p.y; return ; }
    else if(fabs(l.a)<EPS){ ans.x = p.x; ans.y = -(l.c); return ; }
    else{ line perpendicluar; pointSlopeToLine(p, 1/l.a, perpendicluar); areIntersect(l, perpendicluar, ans); return ; }
}
double distToLine(point p, point a, point b, point &c)
{
    line l; pointsToLine(a, b, l); closestPoint(l, p, c); return dist(p,c);
}
double distToLine(point p, point a, point b)
{
    vec ab = toVec(a,b); vec ap = toVec(a,p); return fabs(cross(ab,ap))/sqrt(norm_sq(ab));
}
double distToLineSegment(point p, point a, point b)
{
    if(dot(toVec(a,b),toVec(b,p))>0) return dist(p,b); if(dot(toVec(b,a),toVec(a,p))>0) return dist(p,a); return distToLine(p,a,b);
}
int insideCircle(point p, point c, int r)
{
    double dx = p.x-c.x, dy = p.y-c.y; double d = dx*dx + dy*dy; int ret;
    if(d<r*r) ret = 0; else if(d==r*r) ret = 1; else ret = 2; return ret;
}
double area (double a, double b, double c) { double s = (a+b+c)/2.0; return sqrt(s*(s-a)*(s-b)*(s-c)); }
double rInCircle(double ab, double bc, double ca){ double s = (ab + bc + ca)/2.0; return area(ab, bc, ca)/s; }
double rCircumCircle(double ab, double bc, double ca) { return (ab * bc * ca) / (4 * area(ab, bc, ca)); }
double rCircumCircle(point a, point b, point c) { return rCircumCircle(dist(a,b), dist(b,c), dist(c,a)); }
void circumCircle(point A, point B, point C, point &ctr, double &r)
{
    line AB, AC, l1, l2; pointsToLine(A, B, AB); pointsToLine(A, C, AC);
    if(AB.a==0){ l1 = line(1,0,-((A.x+B.x)/2.0)); }
    else if(AB.b==0){ l1 = line(0,1,-((A.y+B.y)/2.0)); }
    else{ pointSlopeToLine(point((A.x+B.x)/2.0, (A.y+B.y)/2.0), 1/AB.a, l1); }
    if(AC.a==0){l2 = line(1,0,-((A.x+C.x)/2.0)); }
    else if(AC.b==0){l2 = line(0,1,-((A.y+C.y)/2.0)); }
    else{ pointSlopeToLine(point((A.x+C.x)/2.0, (A.y+C.y)/2.0), 1/AC.a, l2); }
    areIntersect(l1, l2, ctr);    r = dist(ctr, A); return ;
}
double perimeter (vector<point>P)
{
    double res = 0; for(int i=0; i+1<P.size(); i++) {res+=dist(P[i],P[i+1]); } return res;
}
double area(vector<point>P)
{
    double res = 0;
    for(int i=0; i+1<P.size(); i++)
    {
        double x1, y1, x2, y2; x1 = P[i].x, y1 = P[i].y; x2 = P[i+1].x, y2 = P[i+1].y;res+=x1*y2 - x2*y1;
    }
    return fabs(res)/2.0;
}

bool isConvex(vector<point>P)
{
    int sz = P.size(); if(sz<=3) return false; bool isLeft = ccw(P[0], P[1], P[2]);
    for(int i=1; i+1<sz; i++) {if(ccw(P[i],P[i+1],P[(i+2)==sz ? 1 : i+2])!=isLeft) return false;} return true;
}
bool inPolygon(vector<point>P, point pt)
{
    if(P.size()==0) return false; int sz = P.size(); double sum = 0;
    for(int i=0; i+1<sz; i++)
    {
        if(ccw(pt,P[i],P[i+1])) sum+=angle(P[i],pt,P[i+1]);
        else sum-=angle(P[i],pt,P[i+1]);
    }
    if(fabs(fabs(sum)-2*PI)<EPS) return true; else return false;
}
bool inPolygon2(vector<point>P, point pt)
{
    if(P.size()==0) return false; int sz = P.size(); double sum = 0;
    for(int i=0; i+1<sz; i++)
    {
        if(coLinear(pt,P[i],P[i+1]) && pt.x>=min(P[i].x,P[i+1].x) && pt.x<=max(P[i].x, P[i+1].x) && pt.y>=min(P[i].y,P[i+1].y) && pt.y<=max(P[i].y,P[i+1].y)) return true;
        if(ccw(pt,P[i],P[i+1])) sum+=angle(P[i],pt,P[i+1]); else sum-=angle(P[i],pt,P[i+1]);
    }
    //cout<<"inp "<<pt.x<<" "<<pt.y<<" "<<fabs(sum)<<endl;
    if(fabs(fabs(sum)-2*PI)<EPS) return true; else return false;
}
point pivot(0,0);
bool angleCmp(point a, point b)
{
    if(coLinear(a,b,pivot)) return dist(pivot,a) < dist(pivot,b);
    double dx1 = a.x-pivot.x, dy1 = a.y-pivot.y; double dx2 = b.x-pivot.x, dy2 = b.y-pivot.y;
    return (atan2(dy1,dx1)-atan2(dy2,dx2)) < 0;
}

bool cmp(point a, point b){if(a.x==b.x) return a.y<b.y; return a.x<b.x;}

vector<point> CH(vector<point>P)
{
    int p0 = 0, sz = P.size();
    if(sz<=3){ if(!(P[0]==P[sz-1])) P.push_back(P[0]); return P; }
    for(int i=1; i<sz; i++) { if(P[i].y<P[p0].y || (P[i].y==P[p0].y && P[i].x>P[p0].x)) p0 = i;}
    swap(P[0],P[p0]); pivot = P[0]; sort(++P.begin(), P.end(),angleCmp);
    for(int i=0; i<sz; i++) { cout<<"as "<<P[i].x<<" "<<P[i].y<<endl; }

    vector<point>ret; ret.push_back(P[sz-1]); ret.push_back(P[0]); ret.push_back(P[1]); int i = 2;
    while(i<sz)
    {
        int j = ret.size()-1; if(ccw(ret[j-1],ret[j],P[i])) ret.push_back(P[i++]); else ret.pop_back();
    }
    return ret;
}

vector<point>CH2(vector<point>P)
{
    int n = P.size(); if(n<=1) return P; sort(P.begin(), P.end(),cmp); point p1 = P[0], p2 = P.back();
    line l; pointsToLine(p1,p2,l);bool flag = true;
    for(int i=0; i<n; i++)
    {
        double tmp = l.a*P[i].x + l.b*P[i].y + l.c; if(fabs(tmp)<EPS) continue; else flag = false;
    }
    if(flag){ P.push_back(P[0]); return P; }
    vector<point>up,down,ret; up.push_back(p1); down.push_back(p1);
    for(int i=1; i<n; i++)
    {
        if(i==P.size()-1 || (!ccw(p1,P[i],p2))){
            while(up.size()>=2 && ccw(up[up.size()-2],up[up.size()-1],P[i])) up.pop_back();
            up.push_back(P[i]);
        }
        if(i==P.size()-1 || !cw(p1,P[i],p2)){
            while(down.size()>=2 && cw(down[down.size()-2],down[down.size()-1],P[i]))
                down.pop_back();
            down.push_back(P[i]);
        }
    }

    for(int i=0; i<up.size(); i++) ret.push_back(up[i]);
    for(int i=down.size()-2; i>=0; i--) ret.push_back(down[i]);
    return ret;
}
