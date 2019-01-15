# Query-string
```sh
curl -H "Content-Type: application/json" -XGET 'localhost:9200/topics_index/_search' -d '
{
    "query": {
        "match": {
            "title": "Ducimus"
        }
    }
}
'
```
