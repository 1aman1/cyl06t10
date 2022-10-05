class Solution
{
    vector<vector<bool>> visited;

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int new_color)
    {
        visited.resize(image.size());
        for (int i = 0; i < visited.size(); ++i)
            visited[i].resize(image[0].size());

        paint(image, sr, sc,
              image[sr][sc],
              new_color);

        return image;
    }

private:
    void paint(vector<vector<int>> &image, int sr, int sc,
               int start_colour,
               int new_color)
    {
        bool rowCheck = 0 <= sr && sr < image.size();
        bool colCheck = 0 <= sc && sc < image[0].size();

        if (!rowCheck || !colCheck)
            return;

        if (image[sr][sc] != start_colour)
            return;

        if (visited[sr][sc] == true)
            return;

        visited[sr][sc] = true;
        image[sr][sc] = new_color;

        paint(image, sr + 1, sc, start_colour, new_color);
        paint(image, sr - 1, sc, start_colour, new_color);
        paint(image, sr, sc + 1, start_colour, new_color);
        paint(image, sr, sc - 1, start_colour, new_color);
    }
};