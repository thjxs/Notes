# Grid

* grid-row-start, grid-row-end, grid-column-start, grid-column-end

Values auto|<custom-ident>|[<integer> && <custom-ident>?]|[span&&[<integer>]||<custom-ident>]]
Initial value auto


# sample
```
#grid {
	display: grid;
	grid-template-areas:
		"header header header header"
		"leftside content content rightside"
		"leftside footer footer footer"
	grid-template-rows: 200px 1fr 3em;
	grid-template-columns: 20em 1fr 1fr 10em;
}