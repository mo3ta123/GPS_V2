#include "Distance.h"

double toRadians(const double degree)
{
		double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
float distance(float lat1,float long1,
                     float lat2,float long2)
{		
		float dlong,dlat,ans,R;
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    dlong = long2 - long1;
    dlat = lat2 - lat1;
 
    ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    R = 6371;
     
    // Calculate the result
    ans = ans * R;
		
		ans*=1000;
    return ans;
}
