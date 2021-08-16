#include <bits/stdc++.h>

using namespace std;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ptrdiff_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;

using f32 = float_t;
using f64 = double_t;

template <typename T> using vec = vector<T>;
template <typename T> using vec_deq = deque<T>;
template <typename T> using linked_list = list<T>;

template<typename T> using hash_set = unordered_set<T>;
template<typename T> using btree_set = set<T>;

template<typename K, typename V> using hash_map = unordered_map<K, V>;
template<typename K, typename V> using btree_map = map<K, V>;

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vec<T>, greater<T>>;

template<typename T> using fn = function<T>;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

auto main() -> i32 {

    ios::sync_with_stdio(false), cin.tie(nullptr);

    usize T = 1; cin >> T;
    for (usize t = 1; t <= T; t++) {

        i32 n;
        i64 c;
        cin >> n >> c;

        vec<pair<i64, i32>> p;
        for (i32 i = 1; i <= n; i++) {
            i64 l, r;
            cin >> l >> r;
            p.push_back({ l + 1,1 });
            p.push_back({ r,-1 });
        }

        sort(p.begin(), p.end());

        map<i64, i64, greater<i64>> m;

        i64 cur_h = 0;
        i64 last = 1;
        for (auto point : p) {
            m[cur_h] += point.first - last;
            last = point.first;
            cur_h += point.second;
        }

        i64 ans = (i64)n;

        for (auto x : m) {
            cout<<c<<" "<<x.first<<" "<<x.second<<endl;
            if (c == 0) {
                break;
            }
            if (x.second <= c) {
                ans += x.second * x.first;
                c -= x.second;
            }
            else {
                ans += c * x.first;
                c = 0;
            }
        }



        cout << "Case #" << t << ": ";
        cout << ans << "\n";
    }
    return 0;
}
