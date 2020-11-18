# life cycle

## Mounting

* constructor() // init state and bind methods
* static getDerivedStateFromProps()
* render() // return React elements, Arrays, Portals, String or Booleans
* componentDidMount() // component is mounted(inserted into the tree)

## Updating

* static getDerivedStateFromProps()
* shouldComponentUpdate()
* render() // will not be invoked if *souldComponentUpdate()* returns false
* getSnapshotBeforeUpdate()
* componentDidUpdate() // operate on the DOM or network request

## Unmounting

* componentWillUnmount() // component is unmounted and destroyed

## Error Handling

* static getDerivedStateFromError()
* componentDidCatch()
