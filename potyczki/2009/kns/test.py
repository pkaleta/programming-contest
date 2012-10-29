from PIL import Image

k = 12
n = 4
w = 30
h = 30

v = []

v = [[False for i in range(w)] for j in range(h)]


def dfs(x, y, img, d):
    if x in range(w) and y in range(h) and not v[x][y]:
        v[x][y] = True
        img.putpixel((x, y), 100)
        dfs(x + k, y + n, img, d + 1)
        dfs(x + k, y - n, img, d + 1)
        dfs(x - k, y - n, img, d + 1)
        dfs(x - k, y + n, img, d + 1)
        dfs(x + n, y + k, img, d + 1)
        dfs(x + n, y - k, img, d + 1)
        dfs(x - n, y - k, img, d + 1)
        dfs(x - n, y + k, img, d + 1)


image = Image.new("RGB", (w, h))
dfs(w/2, h/2, image, 0)
image.putpixel((w/2, h/2), 300)
image.show()

