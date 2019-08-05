///Fahim Ahmed :: Dhaka Residential Model College
#pragma comment(linker, "/STACK:16777216") ///Increases Stack size
#include <bits/stdtr1c++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
///// A red-black tree table storing ints and their order
///// statistics. Note that since the tree uses
///// tree_order_statistics_node_update as its update policy, then it
///// includes its methods by_order and order_of_key.
//typedef
//tree<
//  int,
//  null_type,
//  less<int>,
//  rb_tree_tag,
//  // This policy updates nodes' metadata for order statistics.
//  tree_order_statistics_node_update>
//set_t; ///works like set but keeps order
///*
//    extra methods:
//    set_t.find_by_order(order);
//    set_t.order_of_key(key);
//*/
#define li long long int
#define ui unsigned long long int
///I/O functions BEGIN
#define rfile(a) freopen(a, "r", stdin)
#define wfile(a) freopen(a, "w", stdout)
#define rd(a) scanf("%lf", &a)
#define lb printf("\n")
#define ru(n) scanf("%llu",&n)
#define rl(n) scanf("%I64d", &n)
#define ri(n) scanf("%d", &n)
#define rs(n) scanf("%[^\n]",n)
#define rtok(n) scanf("%s",n)
#define MAX_BUFFER_SIZE 200001
char buff[MAX_BUFFER_SIZE];
///REGEX in scanf
/*
    CASE 1: You want to keep scanning as long as you get
            Lower or Upper Case letters, (a-z and A-Z),
            digits(0-9), comma and dash
            char buff[MAX_BUFFER_SIZE];*/
///         scanf("%[a-z,A-Z,0-9,,,-]", buff);
/*          put the characters or character ranges you want to scan seperated by a comma
            a-z , , , A-Z -> IN THIS WAY
*////       If you have ',' as a input argument keep it also seperated by a comma [a-z, , , A-Z]
/*
    CASE 2: You want to keep scanning until you get
            '\n', or '_' or ';'*/
///         scanf("%[^\n,_,;], buff);
/*          The comma separation is same way as previous case.
            Simply put a '^' before specifying the delimiters
            delimiters means, end symbols
*/
///Use printf to output anything
///For string you can also use puts(string.c_str());
///IO functions END
#define pi acos(-1.000)
#define pb push_back
#define mp make_pair
#define Pr printf
#define For(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000003
#define eps 1e-9
#define pii pair<int,int>

inline double fgcd(double x,double y){
	return fabs(y)<1e-4?x:fgcd(y,fmod(x,y));
}

template <typename t1> t1 gcd(t1 a, t1 b) {while(b != 0 ){a=a%b;a = a^b;b = b^a;a = a^b;}return a;}
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }
template <typename t1> bool check (t1 i, t1 k){return i&((t1)1<<k);}
template <typename t1> t1 On(t1 i, t1 k) { return i|((t1)1 << k);}
template <typename t1> t1 Off(t1 i, t1 k) {return (i-((check(i,k))<<k) );}
inline double Cos(double value){value=cos(value);return (fabs(value-0.00) <= eps)?0.00:value;}
inline double Sin(double value){value=sin(value);return (fabs(value-0.00) <= eps)?0.00:value;}
inline double Tan(double value){value=tan(value);return (fabs(value-0.00) <= eps)?0.00:value;}

///Real number comparison
/*
Some more Real Number Techniques:
to compare between double a and double b
if(a == b) -> if(fabs(a-b)<eps)
if(a > b) -> if((a-b) >= eps)
if(a >= b) -> if((a-b) >= eps || fabs(a-b) < eps)
*/

///Info section
//string to char array
/* char arr[] = string_name.c_str();*/
//char array to string
/*string string_name(arr);*/
//fastest way to print c++ string
/* puts(str.c_str()) or printf("%s\n", str.c_str());*/
/*
To find the lengths of a triangle from all three angles only is not possible.
At least 2 angles and one side is required
*/
///Convert number to string
string num2string(int val)
{
    stringstream ss;
    ss<<val;
    string s;
    ss>>s;
    return s;
}

///Geometry formula
double rad_to_deg(double x)
{
    return x*(180.000/pi);
}
double deg_to_rad(double x)
{
    return x*(pi/180.000);
}
double cosine_rule(double b,double c,double a){
    double value = (0.5)*(b/c) + (0.5)*(c/b) - (0.5)*(a/b)*(a/c);
    return acos(value);
}
vector<double> tri_side_to_angle(double a,double b, double c)
{
    double A,B,C;
    A = cosine_rule(b,c,a);
    B = cosine_rule(a,c,b);
    C = pi-A-B;
    double arr[] = {A,B,C};
    //copy an array into a vector
    vector<double> ret (arr, arr + sizeof(arr) / sizeof(double));
    return ret;
}
double tri_area(double a, double b, double c)
{
    double p = (a+b+c)/2.0;
    double area = p*(p-a)*(p-b)*(p-c);
    return sqrt(area);
}
double circle_area(double r)
{
    return pi*r*r;
}
double circle_peripheri(double r)
{
    return 2.0*pi*r;
}
struct pts{
    double x,y;
    pts(){}
    pts(double xx,double yy)
    {
        x = xx;
        y=yy;
    }
    bool operator < (const pts& ot) const{
        if(this->y > ot.y) return true;
        else if(this-> y == ot.y)
        {
            return (this->x < ot.x);
        }
        else return false;
    }
    bool operator != (const pts& ot)const{
        if(this->x==ot.x && this->y == ot.y)return false;
        else return true;
    }
    double distance(pts ot)
    {
        return sqrt((x-ot.x)*(x-ot.x) + (y-ot.y)*(y-ot.y));
    }
    bool diagonal_aligned(pts ot)
    {
        return fabs(x-ot.x)==(fabs(y-ot.y));
    }
    pts translate(double dx,double dy){
        pts ret(x+dx,y+dy);
        return ret;
    }
    pts rotate_about(pts ot, double theta){
        pts translated = this->translate(-ot.x, -ot.y);
        pts changed;
        changed.x = translated.x*Cos(deg_to_rad(theta)) - translated.y*Sin(deg_to_rad(theta));
        changed.y = translated.x*Sin(deg_to_rad(theta)) + translated.y*Cos(deg_to_rad(theta));
        pts ret = changed.translate(ot.x,ot.y);
        return ret;
    }
};

pts internal_partition(pts a, pts b,double left_ratio, double right_ratio)// partition by a:b ratio
{
    double xx = (left_ratio*b.x + right_ratio*a.x)/(left_ratio+right_ratio);
    double yy = (left_ratio*b.y + right_ratio*a.y)/(left_ratio+right_ratio);
    return pts(xx,yy);
}
pts internal_partition(pts a, pts b,double Ratio)
{
    double k=1/Ratio;
    double xx = (1.0*b.x + k*a.x)/(1+k);
    double yy = (1.0*b.y + k*a.y)/(1+k);
    return pts(xx,yy);
}
pts external_partition(pts a, pts b,double left_ratio, double right_ratio)// partition by a:b ratio
{
    double xx = (left_ratio*b.x - right_ratio*a.x)/(left_ratio-right_ratio);
    double yy = (left_ratio*b.y - right_ratio*a.y)/(left_ratio-right_ratio);
    return pts(xx,yy);
}
pts external_partition(pts a, pts b,double Ratio)
{
    double k=1/Ratio;
    double xx = (1.0*b.x - k*a.x)/(1-k);
    double yy = (1.0*b.y - k*a.y)/(1-k);
    return pts(xx,yy);
}
pts middle_point(pts a, pts b){
    double xx=(a.x+b.x)/2.0;
    double yy=(a.y+b.y)/2.0;
    return pts(xx,yy);
}
double area_of_polygon(vector<pts> points)
{
    int sizee = points.size();
    double left_part = points[sizee-1].x*points[0].y;
    for(int i=0;i<sizee-1;i++)
    {
        left_part+=points[i].x*points[i+1].y;
    }
    double right_part = points[sizee-1].y*points[0].x;
    for(int i=0;i<sizee-1;i++)
    {
        right_part+=points[i].y*points[i+1].x;
    }
    return 0.5*fabs(left_part-right_part);
}
struct line {
    double a, b, c;
    double slope;
    double length;
    line() {
        length = -1;///nonexistent
    }
    line( pts p1, pts p2 ) {
        a = p1. y - p2. y;
        b = p2. x - p1. x;
        c = p1. x * p2. y - p2. x * p1. y;
        length = p1.distance(p2);
        check_equation();
    }
    line(double aa,double bb, double cc)
    {
        a = aa;
        b=bb;
        c=cc;
        length = -1;///nonexistent
        check_equation();
    }
    void set_eqn( pts p1, pts p2 ) {
        a = p1. y - p2. y;
        b = p2. x - p1. x;
        c = p1. x * p2. y - p2. x * p1. y;
        check_equation();
    }
    void check_equation()
    {
        if(a==-0)a=0;
        if(b==-0)b=0;
        if(c==-0)c=0;

        if(a==0 and b!=0){
            c/=b;
            b/=b;
            if(b < 0){
                b*=-1;
                c*=-1;
            }
        }
        else if(b==0 and a!=0){
            c/=a;
            a/=a;
            if(a < 0){
                a*=-1;
                c*=-1;
            }
        }

        if(b!=0)slope = -1*(a/b);
        else{
            slope=INFINITY;
        }
    }
    pts intersection(line l2)
    {
        line l1(a,b,c);
        double y = (l2.a*l1.c - l1.a*l2.c);
        double hor1 = (l1.a*l2.b-l2.a*l1.b);
        if(l1.slope == l2.slope)///if they are parallel
        {
            return pts(DBL_MAX,DBL_MAX);///(intersection at infinity)
        }
        y/=(l1.a*l2.b-l2.a*l1.b);
        double x = (-1*l1.c-l1.b*y);
        x/=l1.a;
        pts ret(x,y);
        return ret;
    }
    line rotation_about(pts center_of_rotation, double theta)
    {
        double nx,ny;
        ///let nx=1.0;
        nx=1.0;
        ny = (-(this->a)*nx - this->c)/this->b;
        pts npnt(nx,ny);
        pts rotated_pnt = npnt.rotate_about(center_of_rotation,theta);
        line ret(center_of_rotation, rotated_pnt);
        return ret;
    }
    line perpendicular(pts bb) ///a line perpendicular to line aa and goes through point bb
    {
        line la(this->b,-1*this->a,(this->a*bb.y - this->b*bb.x));
        return la;
    }
    line parallel(pts bb) ///a line parallel to line aa and goes through point bb
    {
        line la(this->a,this->b,-1*(this->a*bb.y + this->b*bb.x));
        return la;
    }
};
///gives the tangent equations from point a on a circle with radius r, and center b
vector<line> tangent_eq(pts a, pts b, double r)
{
    double dx = a.x-b.x;
    double dy = b.y-a.y;
    double m1 = 2*dy*dx + sqrt(4*dy*dy*dx*dx + 4*(r*r - dx*dx)*(dy*dy - r*r));
    double m2 = 2*dy*dx - sqrt(4*dy*dy*dx*dx + 4*(r*r - dx*dx)*(dy*dy - r*r));
    m1/=(2*(r*r-dx*dx));
    m2/=(2*(r*r-dx*dx));
    double c1 = a.y - m1*a.x;
    double c2 = a.y - m2*a.x;
    line la(m1,-1,c1),l2(m2,-1,c2);
    vector<line> ret;
    ret.pb(la); ret.pb(l2);
    return ret;
}


vector<double> line_intersection_angles(line l1, line l2){
    double m1=l1.slope,m2=l2.slope;
    double actual_angle=fabs(atan((m1-m2)/(1.0+m1*m2)));
    double angle_pos=actual_angle;
    double angle_neg=pi-angle_pos;
    vector<double> ret;
    ret.pb(angle_pos);
    ret.pb(angle_neg);
    return ret;
}
line line_intersecting_obtuse_bisector(line l1, line l2){
    double co_efficient_l1 = sqrt(l1.a*l1.a + l1.b*l1.b);
    double co_efficient_l2 = sqrt(l2.a*l2.a + l2.b*l2.b);
    if(l1.a*l2.a + l1.b+l2.b > 0){
        line ret;
        ret.a = (l1.a/co_efficient_l1)-(l2.a/co_efficient_l2);
        ret.b = (l1.b/co_efficient_l1)-(l2.b/co_efficient_l2);
        ret.c = (l1.c/co_efficient_l1)-(l2.c/co_efficient_l2);
        return ret;
    }
    else if(l1.a*l2.a + l1.b+l2.b < 0){
        line ret;
        ret.a = (l1.a/co_efficient_l1)+(l2.a/co_efficient_l2);
        ret.b = (l1.b/co_efficient_l1)+(l2.b/co_efficient_l2);
        ret.c = (l1.c/co_efficient_l1)+(l2.c/co_efficient_l2);
        return ret;
    }
    else{
        ///means lines are parallel, so no bisector, just return l1
        return l1;
    }
}
line line_intersecting_acute_bisector(line l1, line l2){
    double co_efficient_l1 = sqrt(l1.a*l1.a + l1.b*l1.b);
    double co_efficient_l2 = sqrt(l2.a*l2.a + l2.b*l2.b);
    if(l1.a*l2.a + l1.b+l2.b < 0){
        line ret;
        ret.a = (l1.a/co_efficient_l1)-(l2.a/co_efficient_l2);
        ret.b = (l1.b/co_efficient_l1)-(l2.b/co_efficient_l2);
        ret.c = (l1.c/co_efficient_l1)-(l2.c/co_efficient_l2);
        return ret;
    }
    else if(l1.a*l2.a + l1.b+l2.b > 0){
        line ret;
        ret.a = (l1.a/co_efficient_l1)+(l2.a/co_efficient_l2);
        ret.b = (l1.b/co_efficient_l1)+(l2.b/co_efficient_l2);
        ret.c = (l1.c/co_efficient_l1)+(l2.c/co_efficient_l2);
        return ret;
    }
    else{
        ///means lines are parallel, so no bisector, just return l1
        return l1;
    }
}
line line_intersecting_angle_bisector(line l1, line l2, pts target) ///jei bindu borabor bisector ta tana hobe
{
    double position_of_point = (l1.a*target.x + l1.b*target.y+l1.c)*(l2.a*target.x + l2.b*target.y+l2.c)*(l1.a*l2.a + l1.b*l2.b);
    if(fabs(position_of_point - 0.0) <= eps){
        ///this means the point is the intersection point of the lines. Any bisector would satisfy.
        return line_intersecting_acute_bisector(l1,l2);
    }
    else if((position_of_point-0.00) > eps){
        ///this meanse position > 0, the point is in the obtuse (theta > 90) angle
        return line_intersecting_obtuse_bisector(l1,l2);
    }
    else{
        ///this meanse position < 0, the point is in the acute (theta < 90) angle
        return line_intersecting_acute_bisector(l1,l2);
    }
}
bool is_integer(double v)
{
   return floor(v)==ceil(v) ? 1:0;
}

double tri_area_pts(pts a, pts b, pts c)
{
    double x = a.distance(b);
    double y = b.distance(c);
    double z = c.distance(a);
    return tri_area(x,y,z);
}

struct pts3d{
    double x,y,z;
    pts3d(){}
    pts3d(double xx,double yy,double zz)
    {
        x = xx;
        y=yy;
        z=zz;
    }
    bool operator < (const pts3d& ot) const{
        if(this->z > ot.z) return true;
        else if(this-> z == ot.z)
        {
            if(this->y > ot.y)return true;
            else if(this->y == ot.y)
            {
                return (this->x < ot.x);
            }
            else return false;
        }
        else return false;
    }
    bool operator != (const pts3d& ot)const{
        if(this->x==ot.x && this->y == ot.y && this->z == ot.z)return false;
        else return true;
    }
    double distance(pts3d ot)
    {
        return sqrt((x-ot.x)*(x-ot.x) + (y-ot.y)*(y-ot.y) + (z-ot.z)*(z-ot.z));
    }
    pts3d translate(double dx,double dy, double dz){
        pts3d ret(x+dx,y+dy,z+dz);
        return ret;
    }
};

struct Vector3d{
    double x,y,z; ///where the vector is xI + yJ + zK
    double unitX,unitY,unitZ;
    Vector3d(){}
    Vector3d(pts3d a, pts3d b)
    {
        x=b.x - a.x;
        y=b.y-a.y;
        z=b.z-a.z;
    }
    Vector3d(double xx, double yy, double zz)
    {
        x=xx,y=yy,z=zz;
    }
    double absolute()
    {
        return sqrt(x*x + y*y + z*z);
    }
    void assign_value(double xx, double yy, double zz)
    {
        x=xx,y=yy,z=zz;
    }
    void normalize()
    {
        double abs_val=this->absolute();
        x/=abs_val;
        y/=abs_val;
        z/=abs_val;
    }
    double dot_product(Vector3d ot)
    {
        return (x*ot.x + y*ot.y + z*ot.z);
    }
    Vector3d cross_product(Vector3d ot)
    {
        Vector3d res;
        res.assign_value((y*ot.z - z*ot.y), (z*ot.x-x*ot.z), (x*ot.y-y*ot.x));
        return res;
    }
    void calculate_unit_vector()
    {
        double abs_val=this->absolute();
        unitX=(x/abs_val),unitY=(y/abs_val),unitZ=(z/abs_val);
    }
    double angle_between(Vector3d b)
    {
        double numerator = this->dot_product(b);
        double denominator = this->absolute()*b.absolute();
        return (acos(numerator/denominator));
    }
    bool are_parallel(Vector3d b)
    {
        return ((this->cross_product(b).absolute())==0.0)? 1:0;
    }
    bool are_perpendicular(Vector3d b)
    {
        return this->dot_product(b)==0? 1:0;
    }
    bool same_plane(Vector3d b, Vector3d c)
    {
        return this->dot_product(b.cross_product(c)) == 0 ? 1:0;
    }
    double angle_with_X()
    {
        return (acos(x/this->absolute()));
    }
    double angle_with_Y()
    {
        return (acos(y/this->absolute()));
    }
    double angle_with_Z()
    {
        return (acos(z/this->absolute()));
    }

    Vector3d operator +=(const Vector3d& b)
    {
        Vector3d res;
        res.assign_value(x+b.x, y+b.y, z+b.z);
        return res;
    }

    Vector3d operator -=(const Vector3d& b)
    {
        Vector3d res;
        res.assign_value(x-b.x, y-b.y, z-b.z);
        return res;
    }
    void print(){
        cout<<this->x << " " << this->y << " " <<this->z<<endl;
    }
    Vector3d operator +(const Vector3d& b)const{
        Vector3d res;
        res.assign_value(this->x+b.x, this->y+b.y, this->z+b.z);
        return res;
    }
    Vector3d operator -(const Vector3d& b) const{
        Vector3d res;
        res.assign_value(this->x-b.x, this->y-b.y, this->z-b.z);
        return res;
    }
    Vector3d operator * (const double& value) const{
        Vector3d res;
        res.assign_value((this->x*value),(this->y*value),(this->z*value));
        return res;
    }
    friend Vector3d RodriguesRotation(Vector3d r, Vector3d a, double theta);
};
Vector3d RodriguesRotation(Vector3d r, Vector3d a, double theta){
    Vector3d res;
    Vector3d v1,v2,v3;
    double cos_theta=Cos(deg_to_rad(theta));
    double sin_theta=Sin(deg_to_rad(theta));
    v1=r*cos_theta;
    v2=a*(r.dot_product(a) * (1-cos_theta));
    v3=(a.cross_product(r))*sin_theta;
    res=v1+v2+v3;
    return res;
}

pts3d rotate_about(pts3d P,Vector3d a, double theta){
    double rad_theta=deg_to_rad(theta);
    Vector3d X(1.0,0.0,0.0), Y(0.0,1.0,0.0), Z(0.0, 0.0, 1.0);
    Vector3d rotatedX,rotatedY,rotatedZ;
    rotatedX=RodriguesRotation(X,a,theta);
    rotatedY=RodriguesRotation(Y,a,theta);
    rotatedZ=RodriguesRotation(Z,a,theta);
    pts3d ret;
    ret.x = rotatedX.x*P.x + rotatedY.x*P.y + rotatedZ.x*P.z;
    ret.y = rotatedX.y*P.x + rotatedY.y*P.y + rotatedZ.y*P.z;
    ret.z = rotatedX.z*P.x + rotatedY.z*P.y + rotatedZ.z*P.z;
    return ret;

}
pts3d rotate_about(pts3d P,pts3d center_point,Vector3d a, double theta){
    pts3d translatedP = P.translate(-center_point.x,-center_point.y,-center_point.z);
    pts3d rotated_t_P = rotate_about(translatedP,a,theta);
    pts3d ret=rotated_t_P.translate(center_point.x,center_point.y,center_point.z);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); cerr.tie(0);
    vector<int> a;
    for(int i=1;i<=18;i+=3){
        a.pb(i);
    }
    int n;cin>>n;
    vector<int> :: iterator it=lower_bound(a.begin(),a.end(),n);
    cout<<*it<<endl;
}
