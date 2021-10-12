# react-window
React components for efficiently rendering large lists and tabular data

## Usage
```jsx
import { FixedSizeList as List } from 'react-window';
 
const Row = ({ index, style }) => (
  <div style={style}>Row {index}</div>
);
 
const Example = () => (
  <List
    height={150}
    itemCount={1000}
    itemSize={35}
    width={300}
  >
    {Row}
  </List>
);
```
