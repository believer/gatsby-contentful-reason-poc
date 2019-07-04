[@react.component]
let make = (~data) => {
  let {
    contactTitle,
    header,
    openApplicationLabel,
    openApplicationText,
    contacts,
    opportunities,
  }: Page.Career.t =
    Page.Career.make(data);

  <>
    <Block.Header backgroundImage={header.url}>
      <Typography.H1 color={header.textBgColor}> {header.text} </Typography.H1>
    </Block.Header>
    <main
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      {opportunities
       ->Belt.List.map(opportunity =>
           <Block.Element key={opportunity.id} title={opportunity.title}>
             <Block.Markdown source={opportunity.role} />
             <Link url={"/karriar/" ++ opportunity.urlId}>
               {React.string({j|Läs mer och ansök|j})}
             </Link>
           </Block.Element>
         )
       ->Belt.List.toArray
       ->React.array}
      <Block.Element title=openApplicationLabel>
        <Block.Markdown source=openApplicationText />
      </Block.Element>
    </main>
    <Block.Section color=`RadicalRed>
      <Contacts title=contactTitle contacts />
    </Block.Section>
  </>;
};

let default = make;
