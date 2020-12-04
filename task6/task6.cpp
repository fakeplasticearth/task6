#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
float dist(pair<int, int> dot) {
    float d = sqrt(dot.first * dot.first + dot.second * dot.second);
    return d;
}

vector <pair <int, int> > get_distances(vector <pair<int, int> > coords) {
    vector <pair < float, pair<int, int> > > dist_vector(coords.size());
    vector <pair <float, pair<int, int> > >::iterator d_it1 = dist_vector.begin(), d_it2;
    for (vector<pair<int, int> >::iterator it = coords.begin(); it != coords.end(); it++) {
        pair <float, pair <int, int> > current_pair;
        current_pair = make_pair(dist(*it), make_pair((*it).first, (*it).second));
        *(d_it1 + (it - coords.begin())) = current_pair;
    }

    for (; d_it1 != dist_vector.end(); d_it1++) {
        for (d_it2 = dist_vector.begin() + (d_it1 - dist_vector.begin()) + 1; d_it2 != dist_vector.end(); d_it2++) {
            if ((*d_it1).first > (*d_it2).first) {
                swap(*d_it1, *d_it2);
            }
        }
    }
    vector <pair <int, int> > ans(coords.size());
    vector <pair<int, int> >::iterator it = ans.begin();
    for (d_it1 = dist_vector.begin(); d_it1 != dist_vector.end(); d_it1++) {
        *(it + (d_it1 - dist_vector.begin())) = (*d_it1).second;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector <pair<int, int> > coord_vec(n);
    vector <pair<int, int> >::iterator it = coord_vec.begin();
    for (;it != coord_vec.end();it++){
        int a, b;
        cin >> a >> b;
        (*it).first = a;
        (*it).second = b;
    }
    vector < pair<int, int> > sorted_vec = get_distances(coord_vec);
    for (it = sorted_vec.begin(); it != sorted_vec.end(); it++) {
        cout << (*it).first << ' ' << (*it).second << '\n';
    }
    return 0;
}
