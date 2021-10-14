# Fruit

## Example
```py
import requests
import json
from bs4 import BeautifulSoup

IMG_FOLDER = 'fruit_images/'

FRUIT_URL = 'https://usdawatercolors.nal.usda.gov/'

def run():
    for (index, page) in enumerate(range(380)):
        response = requests.get(FRUIT_URL+'pom/search.xhtml?start={}&searchText=&searchField=&sortField='.format(index * 20))
        soup = BeautifulSoup(response.text, 'html.parser')
        for (div_idx, div) in enumerate(soup.select('div.document')):
            doc = div.select_one('dl.defList')
            artist = doc.select_one(':nth-child(2)>a').get_text()
            year = doc.select_one(':nth-child(4)>a').get_text()
            scientific_name = 'none' if doc.select_one(':nth-child(6)>a') is None else doc.select_one(':nth-child(6)>a').get_text()
            common_name = 'none' if doc.select_one(':nth-child(8)>a') is None else doc.select_one(':nth-child(8)>a').get_text()
            thumb = div.select_one['div.thumb-frame>a>img']('src')
            id = (index + 1) * 20 + div_idx + 1
            info = FruitInfo(id, artist, year, scientific_name, common_name, thumb)
            info.save()

class FruitInfo:
    def __init__(self, id, artist, year, scientific_name, common_name, thumb):
        self.id = id
        self.year = year
        self.scientific_name = scientific_name
        self.common_name = common_name
        self.thumb = thumb
        self.origin = self.__parse_origin()

    def __parse_origin(self):
        id = self.thumb.split('/')[2]
        return FRUIT_URL+'download/{}/screen'.format(id)

    def save(self):
        json_dict = {'origin': self.origin, 'thumb': self.thumb, 'id': self.id, 'year': self.year, 'scientific_name': self.scientific_name, 'common_name': self.common_name}
        with open('./fruit.json', 'a') as f:
            json.dump(json_dict, f)

if __name__ == '__main__':
    run()
```