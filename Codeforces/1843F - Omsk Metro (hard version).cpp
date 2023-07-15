#include <bits/stdc++.h>

struct info{
    //Prefix sum arrays of binary length starting either from ancestor or actual node
    int sum, minNodeUp, maxNodeUp, minAncestorDown, maxAncestorDown, minSeg, maxSeg;
    //Initialization
    info (int x = 0){
        sum = x;
        minSeg = minNodeUp = minAncestorDown = std::min(x, 0);
        maxSeg = maxNodeUp = maxAncestorDown = std::max(x, 0);
    }
};

//VERY IMPORTANT THAT a IS THE BEGGINING OF THE PREFIX AND THAT b IS THE SECOND HALF
info merge (info& a, info& b){
    info result;
    result.sum = a.sum + b.sum;
    //2 chunks, either take min of first chunk or second chunk + first chunk
    result.minNodeUp = std::min(a.minNodeUp, b.minNodeUp + a.sum); 
    result.maxNodeUp = std::max(a.maxNodeUp, b.maxNodeUp + a.sum);
    //Since we're starting from b and going down to a
    //minAncestorDown = min of b, min of a combined with b
    result.minAncestorDown = std::min(b.minAncestorDown, a.minAncestorDown + b.sum);
    result.maxAncestorDown = std::max(b.maxAncestorDown, a.maxAncestorDown + b.sum);
    //minSeg = {minSeg of a, minSeg of b, minSeg that lies on a and b}
    //minSeg that lies on a and b want to minimize the vertical height gained on b, and the minimize the downward of a
    result.minSeg = std::min({a.minSeg, b.minSeg, b.minNodeUp + a.minAncestorDown});
    result.maxSeg = std::max({a.maxSeg, b.maxSeg, b.maxNodeUp + a.maxAncestorDown});
    return result;
}

const int MAX_N = 200001;
const int LOG = 18; //2^18 > 200000

int ancestor [MAX_N][LOG]; //NOT INCLUSIVE OF NODE
info ans [MAX_N][LOG]; //Inclusive of node
int depth [MAX_N];

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        //Default root node
        for (int i = 0; i < LOG; i++) ancestor[0][i] = 0;
        ans[0][0] = info(1);
        depth[0] = 0;
        
        int cur = 1; //Current station number, note that this is 0 indexing, so cur = 1 means station 2
        for (int q = 0; q < n; q++){
            char event;
            std::cin >> event;
            //Add station
            if (event == '+'){
                int v, x;
                std::cin >> v >> x;
                v--; //Adjust to 0 indexing
                depth[cur] = depth[v] + 1; //Record depth
                //Create sparse table for ancestor of current node 2^i up
                ancestor[cur][0] = v; //Remember tree is rooted at 1
                for (int i = 1; i < LOG; i++){
                    ancestor[cur][i] = ancestor[ancestor[cur][i - 1]][i - 1];
                }
                //Create sparse table for prefix and suffix sum information on path from cur --> cur + 2^i up
                ans[cur][0] = info(x);
                //std::cout << ans[cur][0].sum << ' ' << ans[cur][0].minNodeUp << ' ' << ans[cur][0].maxNodeUp << ' ' << ans[cur][0].minAncestorDown << ' ' << ans[cur][0].maxAncestorDown << ' ' << ans[cur][0].minSeg << ' ' << ans[cur][0].maxSeg << '\n';
                for (int i = 1; i < LOG; i++){
                    ans[cur][i] = merge(ans[cur][i - 1], ans[ancestor[cur][i - 1]][i - 1]);
                    //std::cout << ans[cur][i].sum << ' ' << ans[cur][i].minNodeUp << ' ' << ans[cur][i].maxNodeUp << ' ' << ans[cur][i].minAncestorDown << ' ' << ans[cur][i].maxAncestorDown << ' ' << ans[cur][i].minSeg << ' ' << ans[cur][i].maxSeg << '\n';
                }
                cur++;
            }
            //Answering queries
            else{
                int u, v, k;
                std::cin >> u >> v >> k;
                u--; v--;
                //Recall shortest path on tree between two nodes = node u --> LCA, then LCA --> node v
                //Therefore the subpath must lie somewhere on that path
                //We will combine our information as we traverse this path using binary lifting
                //Step 1. Ensure that node u is lower than node v on the graph
                if (depth[u] < depth[v]){
                    std::swap(u, v);
                }
                //Step 2. Set them to the same depth via binary lifting
                info a, b; //info u, v
                int dif = depth[u] - depth[v];
                for (int i = LOG - 1; i >= 0; i--){
                    if ((dif >> i) & 1) {
                        a = merge(a, ans[u][i]);
                        u = ancestor[u][i];
                    }
                }
                //Edge case, v is the LCA of u and v
                if (u == v){
                    a = merge(a, ans[u][0]);
                }
                //Otherwise, find LCA
                else{
                    //This will bring both nodes directly beneath the LCA
                    for (int i = LOG - 1; i >= 0; i--){
                        if (ancestor[u][i] != ancestor[v][i]){
                            a = merge(a, ans[u][i]);
                            b = merge(b, ans[v][i]);
                            u = ancestor[u][i];
                            v = ancestor[v][i];
                        }
                    }
                    a = merge(a, ans[u][1]); //Merge with the LCA
                    b = merge(b, ans[v][0]); //Do not merge with the LCA
                }
                //IMPORTANT!
                //WE MUST SWAP THE VALUES OF B SINCE A AND B MUST BE CONTIGUOUS AND A MUST BE THE BEGGINING
                //THEREFORE B IS THE TAIL, SWAP ITS VALUES SINCE WE'RE DOING THIS SIDEWAYS
                std::swap(b.minNodeUp, b.minAncestorDown);
                std::swap(b.maxNodeUp, b.maxAncestorDown);
                //Output answer
                info answer = merge(a, b);
                //std::cout << answer.sum << ' ' << answer.minNodeUp << ' ' << answer.maxNodeUp << ' ' << answer.minAncestorDown << ' ' << answer.maxAncestorDown << ' ' << answer.minSeg << ' ' << answer.maxSeg << '\n';
                if (answer.minSeg <= k && k <= answer.maxSeg){
                    std::cout << "YES\n";
                }
                else{
                    std::cout << "NO\n";
                }
            }
        }
    }
    return 0;
}